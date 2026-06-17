#pragma once

namespace Views {
class IMessageCommand 
{
public:
	virtual ~IMessageCommand() {};
	virtual void Run() = 0;
};
} // namespace Views