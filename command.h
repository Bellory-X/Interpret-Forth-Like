#ifndef INTERPRETFORTHLIKE_COMMAND_H
#define INTERPRETFORTHLIKE_COMMAND_H

#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
#include <sstream>
#include <map>
#include "interpreter_error.h"

class Command {
public:
    virtual void apply(std::vector<int>& data) = 0;
};

class Add: public Command {
public:
    void apply(std::vector<int>& data) override {
        if (data.size() < 2) {
            std::stringstream ss;
            ss << "not enough numbers";
            throw interpreter_error(ss.str());
        }
        int a  = data.back();
        data.pop_back();
        int b = data.back();
        data.pop_back();
        data.push_back(a + b);
    }
};

class Sub: public Command {
    void apply(std::vector<int>& data) override {
        if (data.size() < 2) {
            std::stringstream ss;
            ss << "not enough numbers";
            throw interpreter_error(ss.str());
        }
        int a  = data.back();
        data.pop_back();
        int b = data.back();
        data.pop_back();
        data.push_back(a + b);
    }
};

class Mod: public Command {
    void apply(std::vector<int>& data) override {
        if (data.size() < 2) {
            std::stringstream ss;
            ss << "not enough numbers";
            throw interpreter_error(ss.str());
        }
        int a  = data.back();
        data.pop_back();
        int b = data.back();
        data.pop_back();
        data.push_back(a % b);
    }
};

class Div: public Command {
    void apply(std::vector<int>& data) override {
        if (data.size() < 2) {
            std::stringstream ss;
            ss << "not enough numbers";
            throw interpreter_error(ss.str());
        }
        int a  = data.back();
        data.pop_back();
        int b = data.back();
        data.pop_back();
        data.push_back(a / b);
    }
};

class Mul: public Command {
    void apply(std::vector<int>& data) override {
        if (data.size() < 2) {
            std::stringstream ss;
            ss << "not enough numbers";
            throw interpreter_error(ss.str());
        }
        int a  = data.back();
        data.pop_back();
        int b = data.back();
        data.pop_back();
        data.push_back(a * b);
    }
};

class More: public Command {
    void apply(std::vector<int>& data) override {
        if (data.size() < 2) {
            std::stringstream ss;
            ss << 0;
            throw interpreter_error(ss.str());
        }
        auto a = data.end() - 1;
        auto b = data.end() - 2;
        std::cout << (int)(*a > *b) << std::endl;
    }
};

class Less: public Command {
    void apply(std::vector<int>& data) override {
        if (data.size() < 2) {
            std::stringstream ss;
            ss << 0;
            throw interpreter_error(ss.str());
        }
        auto a = data.end() - 1;
        auto b = data.end() - 2;
        std::cout << (int)(*a < *b) << std::endl;
    }
};

class Equals: public Command {
    void apply(std::vector<int>& data) override {
        if (data.size() < 2) {
            std::stringstream ss;
            ss << 0;
            throw interpreter_error(ss.str());
        }
        auto a = data.end() - 1;
        auto b = data.end() - 2;
        std::cout << (int)(*a == *b) << std::endl;
    }
};

class Dup: public Command {
    void apply(std::vector<int>& data) override {
        if (data.empty()) {
            std::stringstream ss;
            ss << "not enough numbers";
            throw interpreter_error(ss.str());
        }
        data.push_back(data.back());
    }
};

class Drop: public Command {
    void apply(std::vector<int>& data) override {
        if (data.empty()) {
            std::stringstream ss;
            ss << "not enough numbers";
            throw interpreter_error(ss.str());
        }
        data.pop_back();
    }
};

class Point: public Command {
    void apply(std::vector<int>& data) override {
        if (data.empty()) {
            std::stringstream ss;
            ss << "not enough numbers";
            throw interpreter_error(ss.str());
        }
        std::cout << data.back() << std::endl;
        data.pop_back();
    }
};

class Emit: public Command {
    void apply(std::vector<int>& data) override {
        if (data.empty()) {
            std::stringstream ss;
            ss << "not enough numbers";
            throw interpreter_error(ss.str());
        }
        std::cout << (char)data.back() << std::endl;
        data.pop_back();
    }
};

class Swap: public Command {
    void apply(std::vector<int>& data) override {
        if (data.size() < 2) {
            std::stringstream ss;
            ss << "not enough numbers";
            throw interpreter_error(ss.str());
        }
        std::swap(*(data.end() -1), *(data.end() -2));
    }
};

class Rot: public Command {
    void apply(std::vector<int>& data) override {
        if (data.size() < 3) {
            std::stringstream ss;
            ss << "not enough numbers";
            throw interpreter_error(ss.str());
        }
        std::swap(*(data.end() -1), *(data.end() -3));
        std::swap(*(data.end() -1), *(data.end() -2));
    }
};

class Over: public Command {
    void apply(std::vector<int>& data) override {
        if (data.size() < 2) {
            std::stringstream ss;
            ss << "not enough numbers";
            throw interpreter_error(ss.str());
        }
        data.push_back(*(data.end() - 2));
    }
};

class Cr: public Command {
    void apply(std::vector<int>& data) override {
        if (data.size() < 2) {
            std::stringstream ss;
            ss << "not enough numbers";
            throw interpreter_error(ss.str());
        }
        std::cout << data.back() << std::endl;
        data.pop_back();
        std::cout << data.back() << std::endl;
        data.pop_back();
    }
};

class PrintString: public Command {
public:
    explicit PrintString(std::string& str) : str_(str){}
    void apply(std::vector<int>& data) override {
        std::cout << str_ << std::endl;
    }

private:
    std::string str_;
};

class AddNumber: public Command {
public:
    explicit AddNumber(int& num) : number_(num){}
    void apply(std::vector<int>& data) override {
        data.push_back(number_);
    }

private:
    int number_;
};

class If: public Command {
public:
    If(std::vector<Command *>& st1, std::vector<Command *>& st2, bool& exist_else): stack_command_(st1), else_stack_command_(st2), exist_else_(exist_else) {}
    void apply(std::vector<int>& data) override {
        if (data.back() == 0) {
            if (exist_else_) {
                processing_command(else_stack_command_, data);
                return;
            }
            return;
        }
        processing_command(stack_command_, data);
    }
private:
    static void processing_command(std::vector<Command *>& stack, std::vector<int>& data) {
        auto it_stack_command = stack.begin();
        while (it_stack_command != stack.end()) {
            (*it_stack_command)->apply(data);
            it_stack_command++;
        }
    }
    std::vector<Command *> stack_command_;
    std::vector<Command *> else_stack_command_;
    bool exist_else_;
};

class Cycle: public Command {
public:
    Cycle(std::vector<Command *>& stack_command, bool& i): stack_command_(stack_command), i_(i){}
    void apply(std::vector<int>& data) override {
        if (data.size() < 2) {
            std::stringstream ss;
            ss << "not enough numbers";
            throw interpreter_error(ss.str());
        }
        int a, b;
        if (i_) {
            a = *(data.end() - 1);
            b = *(data.end() - 2);
            data.pop_back();
            data.pop_back();
        } else {
            a = *(data.end() - 2);
            b = *(data.end() - 1);
            data.pop_back();
        }
        while (a < b) {
            auto it_stack_command = stack_command_.begin();
            while (it_stack_command != stack_command_.end()) {
                (*it_stack_command)->apply(data);
                it_stack_command++;
            }
            a++;
        }
    }
private:
    std::vector<Command *> stack_command_;
    bool i_;
};

/*class NewCommand: public Command {
public:
    explicit NewCommand(std::vector<Command *>& stack) : stack_command_(stack){}
    void apply(std::vector<int>& data) override {
        auto it = stack_command_.begin();
        while (it != stack_command_.end()) {
            (*it)->apply(data);
            it++;
        }
    }
    static std::map<std::string, std::vector<Command *>> command_map;
private:
    std::vector<Command *> stack_command_;
};

class AddCommand: public Command {
public:
    void apply(std::vector<int>& data) override {
    }
};*/

#endif
