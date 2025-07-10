#ifndef UU_SOCOM_TTN_H_
#define UU_SOCOM_TTN_H_

#include <string>
#include <expected>
#include "olap/VCube.hpp"

#include "networks/_impl/stores/LayerStore.hpp"
#include "networks/_impl/stores/MLECubeStore.hpp"

namespace uu {
namespace socom {

/**
 * A TemporalTextNetwork is two-mode netork with one layer representing
 * actors and another representing messages exchanged between the
 * actors. Messages are consumed and produced by the actors at particular
 * times.
 *
 * The network is said to be pure if there is nothing else.
 */

enum TTNType
{
    PURE,
    DEGENERATED
};

class TemporalTextNetwork {
  private:

    TTNType type_;

    std::unique_ptr<net::VCube> nodes_;
    std::unique_ptr<net::LayerStore> layers_;

    net::Network* actors_layer_;
    net::Network* msgs_layer_;

    std::unique_ptr<net::MLECubeStore> interlayer_edges_;


  public:
    const std::string name;

    TemporalTextNetwork(const TemporalTextNetwork &) = delete;
    TemporalTextNetwork(TemporalTextNetwork &&) = default;
    TemporalTextNetwork &operator=(const TemporalTextNetwork &) = delete;
    TemporalTextNetwork &operator=(TemporalTextNetwork &&) = delete;
    TemporalTextNetwork(const std::string &name);

    inline TTNType
    type() const
    { return type_; };

    bool
    is_pure() const noexcept
    { return type_ == TTNType::PURE; };

    const net::VCube*
    actors() const noexcept
    { return actors_layer_->vertices(); };

    std::optional<const net::Vertex*>
    add_actor(const std::string &actor_name);

    std::optional<const std::vector<const net::Vertex*>>
    add_actors(const std::vector<std::string>& actors_name);

    const net::VCube*
    msgs() const noexcept
    { return msgs_layer_->vertices(); };

    std::optional<const net::Vertex*>
    add_msg(const std::string &msg_name);

};



} // namespace socom
} // namespace uu

#endif
