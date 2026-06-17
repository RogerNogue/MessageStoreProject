#pragma once

namespace Views {
class IMessageCommand 
{
public:
	virtual ~IMessageCommand() {};
	virtual void PrintOperation(int operationIndex) = 0;
	virtual void Run() = 0;
};
} // namespace Views