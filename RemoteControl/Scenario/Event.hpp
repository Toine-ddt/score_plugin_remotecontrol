#pragma once
#include <RemoteControl/DocumentPlugin.hpp>
#include <Scenario/Document/Event/EventModel.hpp>

namespace RemoteControl
{
class Event final : public score::Component
{
  COMMON_COMPONENT_METADATA("c12629a1-e77b-42e8-a2dc-9b6532a011c1")
public:
  Event(
      Scenario::EventModel& event,
      DocumentPlugin& doc,
      QObject* parent_comp);
};
}
