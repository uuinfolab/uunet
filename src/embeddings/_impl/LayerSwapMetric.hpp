namespace uu
{
    namespace net
    {
        /**
 * Selection mode, for directed edges.
 * E.g., to compute the IN-degree or OUT-degree of a node.
 */
        enum class LayerSwapMetric
        {
            LAYERS_JACC_SIM,
            LAYERS_JACC_DIST,
            NEIGH_JACC_SIM,
            NEIGH_JACC_DIST
        };
    } // namespace net
} // namespace uu