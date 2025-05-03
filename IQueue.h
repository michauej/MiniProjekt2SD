#pragma once
class IQueue
{
public:
    virtual void insert(int value, int priority) = 0;
    virtual void extractMax() = 0;
    virtual void changePriority(int value, int priority) = 0;
    virtual int getMax() = 0;
    virtual int getSize() = 0;
    virtual ~IQueue() {};
};
