#include "WindowSDL.h"

SDL_Texture* WindowSDL::LoadTexture(const std::string& path)
{
    if (m_textureCache.find(path) != m_textureCache.end())
    {
        return m_textureCache[path];
    }

    SDL_Surface* surface = IMG_Load(path.c_str());
    if (!surface)
    {
        std::cout << "Error loading image: " << path << " - " << IMG_GetError() << std::endl;
        return nullptr;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(m_renderer, surface);
    SDL_FreeSurface(surface);

    if (!texture)
    {
        std::cout << "Error creating texture from " << path << ": " << SDL_GetError() << std::endl;
        return nullptr;
    }

    m_textureCache[path] = texture;
    return texture;
}

void WindowSDL::CapFrameRate(int targetFPS)
{
    Uint32 frameTicks = SDL_GetTicks() - m_lastFrameTime;
    if (frameTicks < 1000 / targetFPS) SDL_Delay(1000 / targetFPS - frameTicks);
    m_lastFrameTime = SDL_GetTicks();
}

std::string WindowSDL::GetResourcePath(const std::string& filename)
{
    return "../../resources/" + filename;
}

int WindowSDL::InitLib()
{
    // Init SDL
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        std::cout << "Error initializing SDL: " << SDL_GetError() << std::endl;
        return 1;
    }

    // Init SDL_ttf (Font)
    if (TTF_Init() == -1)
    {
        std::cout << "Error initializing SDL_ttf: " << TTF_GetError() << std::endl;
        return 1;
    }

    // Init SDL_Image
    if (IMG_Init(IMG_INIT_PNG) < 0)
    {
        std::cout << "Error initializing SDL_image: " << IMG_GetError() << std::endl;
        return 1;
    }

    return 0;
}

int WindowSDL::CreateWindow()
{
    m_window = SDL_CreateWindow("SDL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, W_WINDOW, H_WINDOW, SDL_WINDOW_SHOWN);
    
    if (!m_window)
    {
        std::cout << "Error creating window: " << SDL_GetError() << std::endl;
        return 1;
    }

    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);

    if (!m_renderer)
    {
        std::cout << "Error creating renderer: " << SDL_GetError() << std::endl;
        return 1;
    }

    std::string fontPath = GetResourcePath("Roboto-Regular.ttf");
    m_font = TTF_OpenFont(fontPath.c_str(), 20);

    if (!m_font)
    {
        std::cout << "Error loading font: " << TTF_GetError() << std::endl;
        return 1;
    }

    // Init elements

    m_fps = new TextSDL("", { 10, 10 }, { 0, 255, 0, 255 });

    return 0;
}

bool WindowSDL::IsWindowCreated()
{
    return m_window != nullptr;
}

Player* WindowSDL::CreatePlayer()
{
    std::string path = GetResourcePath("Pokeball.png");
    return new Player(new SpriteSDL(path, 400, 200, m_renderer));
}

Brick* WindowSDL::CreateBrick(int x, int y)
{
    std::string path = GetResourcePath("Pokeball.png");
    return new Brick(new SpriteSDL("Pokeball.png", 400, 200, m_renderer), x, y);
}

void WindowSDL::Draw(std::vector<Sprite*> sprites)
{
    Uint32 startTicks = SDL_GetTicks();

    // FPS Calculation
    static Uint32 lastTicks = startTicks;
    float fps = 1000.0f / (startTicks - lastTicks);
    lastTicks = startTicks;

    m_fps->Update("FPS: " + std::to_string(static_cast<int>(fps)));

    SDL_SetRenderDrawColor(m_renderer, 25, 25, 112, 255); // Background color
    SDL_RenderClear(m_renderer);

    // Render FPS text
    SDL_Surface* surface = TTF_RenderText_Solid(m_font, m_fps->GetValue().c_str(), m_fps->GetColor());
    if (surface)
    {
        SDL_Texture* texture = SDL_CreateTextureFromSurface(m_renderer, surface);
        if (texture)
        {
            SDL_Rect destRect = { m_fps->GetPos().first, m_fps->GetPos().second, surface->w, surface->h };
            SDL_RenderCopy(m_renderer, texture, nullptr, &destRect);
            SDL_DestroyTexture(texture);
        }
        SDL_FreeSurface(surface);
    }

    // Render sprites
    for (auto sprite : sprites)
    {
        SDL_Texture* texture = *reinterpret_cast<SDL_Texture**>(sprite->Get());
        SDL_Rect destRect = { sprite->GetPos().first, sprite->GetPos().second, 100, 100 };
        SDL_RenderCopy(m_renderer, texture, nullptr, &destRect);
    }

    SDL_RenderPresent(m_renderer);
    CapFrameRate(60); // Limit FPS
}

void WindowSDL::Clear()
{
    SDL_RenderClear(m_renderer);
}

void WindowSDL::Kill()
{
    // Libération des textures du cache
    for (auto& [key, texture] : m_textureCache)
    {
        SDL_DestroyTexture(texture);
    }
    m_textureCache.clear();

    // Libération des sprites
    /*for (auto sprite : m_sprites)
    {
        delete sprite;
    }
    m_sprites.clear();*/

    // Fermeture de la police et suppression de m_fps
    if (m_fps)
    {
        if (m_font)
        {
            TTF_CloseFont(m_font);
            m_font = nullptr;
        }
        delete m_fps;
        m_fps = nullptr;
    }

    // Suppression du renderer et de la fenêtre
    if (m_renderer)
    {
        SDL_DestroyRenderer(m_renderer);
        m_renderer = nullptr;
    }

    if (m_window)
    {
        SDL_DestroyWindow(m_window);
        m_window = nullptr;
    }

    // Nettoyage des bibliothèques SDL
    IMG_Quit();
    TTF_Quit();
    SDL_Quit();
}