// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from pal_task_dispatcher.djinni

#pragma once

#include <memory>

namespace core_gen {

class ITask;

class ITaskDispatcher {
public:
    virtual ~ITaskDispatcher() {}

    virtual void dispatchToUI(const std::shared_ptr<ITask> & task) = 0;

    virtual void dispatchToCore(const std::shared_ptr<ITask> & task) = 0;

    virtual void dispatchToDB(const std::shared_ptr<ITask> & task) = 0;

    virtual void dispatchToBG(const std::shared_ptr<ITask> & task) = 0;
};

}  // namespace core_gen
