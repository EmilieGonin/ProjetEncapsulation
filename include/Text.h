#pragma once

#include <iostream>
#include <string>

class Text
{
public:
	void Update(std::string text) { m_value = text; }
	std::string GetValue() const { return m_value; }
	std::pair<int, int> GetPos() const { return m_pos; }

protected:
	std::string m_value;
	std::pair<int, int> m_pos;
};