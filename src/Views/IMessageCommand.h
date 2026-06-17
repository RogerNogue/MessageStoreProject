#pragma once

namespace Views {
class IMessageCommand {
public:
	virtual ~IMessageCommand() {};
	virtual void Run() const = 0;
};
} // namespace Views