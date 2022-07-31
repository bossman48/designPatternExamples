
//Iterator design pattern
#include <vector>
#include <iostream> // std::cout
#include <memory> // std::auto_ptr
#include <algorithm> // std::for_each
using namespace std;

#include <string>
#include <iostream>
//Header File
#include<iostream>
#include<thread>

//state class
class TLState
{
public:
    virtual void HandleReq() = 0;
};

class TLRed: public TLState
{
public:
    static TLRed* GetInstance()
    {
        static TLRed m_pRed;
        return &m_pRed;
    }
    virtual void HandleReq()
    {
        std::cout<<"Red is glowing for 1 sec"<<std::endl;
    }


};

class TLYellow:public TLState
{
public:
    static TLYellow* GetInstance()
    {
        static TLYellow m_pinstance;
        return &m_pinstance;
    }

    void HandleReq()
    {
        std::cout<<"Yellow is glowing for 1 sec"<<std::endl;
    }
};

class TLGreen: public TLState
{
public:
    static TLGreen* GetInstance()
    {
        static TLGreen m_pGreen;
        return &m_pGreen;
    }


    void HandleReq()
    {
        std::cout<<"Green is glowing for 1 sec"<<std::endl;
    }

};

class TLController
{
    TLState* mtlstate;
public:
    TLController()
    {
        mtlstate = nullptr;
    }
    void run()
    {
        int i =0;
        while(i< 3)
        {
            mtlstate = TLRed::GetInstance();
            mtlstate->HandleReq();
            std::this_thread::sleep_for(std::chrono::seconds(1));

            mtlstate = TLYellow::GetInstance();
            mtlstate->HandleReq();
            std::this_thread::sleep_for(std::chrono::seconds(1));

            mtlstate = TLGreen::GetInstance();
            mtlstate->HandleReq();
            std::this_thread::sleep_for(std::chrono::seconds(1));

            i++;
        }

    }

};



int main()
{
    std::cout<<"State Design Pattern"<<std::endl;

    //start
    TLController obj;
    obj.run();
    return 0;
}