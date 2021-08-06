#pragma once
#include <Process/Process.hpp>
#include <Process/ProcessComponent.hpp>

#include <score/model/Component.hpp>
#include <score/model/ComponentFactory.hpp>
#include <score/plugins/ModelFactory.hpp>

#include <RemoteControl/DocumentPlugin.hpp>
#include <score_plugin_remotecontrol_export.h>

namespace RemoteControl
{
class SCORE_PLUGIN_REMOTECONTROL_EXPORT ProcessComponent
    : public Process::GenericProcessComponent<DocumentPlugin>
{
  ABSTRACT_COMPONENT_METADATA(
      RemoteControl::ProcessComponent,
      "b8a691ea-5352-468d-b78c-04e420c252d1")
public:
  ProcessComponent(
      Process::ProcessModel& proc,
      DocumentPlugin& doc,
      const QString& name,
      QObject* parent);

  virtual ~ProcessComponent();
};

template <typename Process_T>
using ProcessComponent_T
    = Process::GenericProcessComponent_T<ProcessComponent, Process_T>;

class SCORE_PLUGIN_REMOTECONTROL_EXPORT ProcessComponentFactory
    : public score::GenericComponentFactory<
          Process::ProcessModel,
          DocumentPlugin,
          ProcessComponentFactory>
{
  SCORE_ABSTRACT_COMPONENT_FACTORY(RemoteControl::ProcessComponent)
public:
  virtual ~ProcessComponentFactory();
  virtual ProcessComponent* make(
      Process::ProcessModel& proc,
      DocumentPlugin& doc,
      QObject* paren_objt) const = 0;
};

template <typename ProcessComponent_T>
class ProcessComponentFactory_T
    : public score::GenericComponentFactoryImpl<
          ProcessComponent_T,
          ProcessComponentFactory>
{
public:
  using model_type = typename ProcessComponent_T::model_type;
  ProcessComponent* make(
      Process::ProcessModel& proc,
      DocumentPlugin& doc,
      QObject* paren_objt) const final override
  {
    return new ProcessComponent_T{
        static_cast<model_type&>(proc), doc, paren_objt};
  }
};

using ProcessComponentFactoryList = score::GenericComponentFactoryList<
    Process::ProcessModel,
    DocumentPlugin,
    ProcessComponentFactory>;
}
