#include "socom/TemporalTextNetwork.hpp"
#include "networks/_impl/observers/PropagateObserver.hpp"

namespace uu {
namespace socom {

TemporalTextNetwork::
TemporalTextNetwork(
    const std::string& name
) : name(name)
{
    type_ = TTNType::PURE;

    nodes_ = std::make_unique<net::VCube>("N");

    layers_ = std::make_unique<net::LayerStore>(nodes_.get());


    actors_layer_ = layers_->add("A", net::EdgeDir::DIRECTED);
    msgs_layer_ = layers_->add("M", net::EdgeDir::DIRECTED);

    interlayer_edges_ = std::make_unique<net::MLECubeStore>(layers_.get());

    auto obs = std::make_unique<
        net::PropagateObserver<
            net::MLECubeStore,
            const net::Network>>
        (interlayer_edges_.get());

    layers_->attach(obs.get());
    layers_->register_observer(std::move(obs));
};

// TODO(dvladek): Change to expected when moving to C++23
// FIXME(dvladek): At this point the library does not check if the actor exists
std::optional<const net::Vertex*>
TemporalTextNetwork::
add_actor(const std::string &actor_name)
{
  auto actor = actors_layer_->vertices()->add(actor_name);
  if (actor == nullptr)
    return {};

  return actor;
}

std::optional<const std::vector<const net::Vertex*>>
TemporalTextNetwork::
add_actors(const std::vector<std::string>& actors_name)
{
  std::vector<const net::Vertex*> actors = {};

  for (auto actor_name : actors_name)
  {
    actors_layer_->vertices()->add(actor_name);
  }

  return actors;
}


} // namespace socom
}
