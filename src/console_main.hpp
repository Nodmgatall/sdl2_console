#ifndef CONSOLE_MAIN_HPP
#define CONSOLE_MAIN_HPP

#include <vector>
#include <map>
#include <string>

class Console
{
    public:
        //member attributes
        //size
        
        //member functions
       // int init(font. position, size, etc);
        int add_command(std::function, std::string command_name);
        int remove_command(std::string key);
        int get_command_list();
    private:
        std::stack<std::string> m_command_history;
        std::vector<std::string> m_console_output;
        std::map<std::string, std::function<void(std::vector<double>)>> m_command_map;
        std::multimap<std::function<void(std::vector<double>, std::string)>> m_alias_map;
        
        
        void move_up();
        void move_donw();
}

#endif
