#include "console.hpp"
Console::add_command(std::function < void(std::vector<double>) command_func,
                     std::string command_name) {
    if (m_command_map.find(command_name) == m_command_map.end()) {
        m_alias_map.insert(command_func, command_name);
        m_command_map.insert(command_name, command_func);
    } else {
        std::err << "Error: command " << command_name << "was not added, command already exists"
                 << std::endl;
    }
}

Console::remove_command(std::string command_name) {

    auto command_it = m_command_map.find(command_name);
    if (command_it != m_command_map.end()) {
        auto alias_it =, m_alias_map.find(command_it.second);
        while (alias_it != m_alias_map.end()) {
            m_command_map.erase(alias_it.second)
        }
        m_alias_map.erase(command_it.second);
    } else {
        std::err << "Error: command " << command_name << "could not be removed, does not exist"
                 << std::endl;
    }
}

Console::get_command_list() {
    std::vector<std::string> command_list;

    for (auto it = m_command_map.begin(); it < m_command_map.end(); it++) {
        auto it = m_alias_map.find(it.second);
        std::string command_info = "";
        while(it != m_alias_map.end())
        {
            command_info.append(it.second);
            command_info.append(" ");
        }
        commad_list.push_back(command_info);
    }
   
}
