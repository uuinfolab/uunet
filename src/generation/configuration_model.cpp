#include "configuration_model.hpp"
#include <limits>
#include "_impl/DegreesOfFreedom.hpp"

namespace uu {
namespace net {

bool
is_graphic(
    const std::vector<size_t> &deg_seq,
    bool is_sorted
)
{
    std::vector<size_t> sorted(deg_seq);

    if (!is_sorted)
    {
        std::sort(sorted.begin(), sorted.end(), std::greater<>());
    }

    size_t left_sum = 0;
    std::vector<size_t> partial_sums(deg_seq.size());
    std::partial_sum(sorted.rbegin(), sorted.rend(), partial_sums.rbegin());
    partial_sums.push_back(0);

    if (partial_sums.front() % 2) // the first condition of the Erdos-Gallai theorem
    {
        return false;
    }

    for (size_t k = 1; k <= sorted.size(); k++)
    {
        left_sum += sorted[k-1];
        auto lower = std::upper_bound(sorted.begin() + k, sorted.end(), k, std::greater<>());
        auto ind = std::distance(sorted.begin(), lower); // sorted[i], where i >= ind are smaller than k

        if (left_sum > k * (ind-1) + partial_sums[ind])
        {
            return false;
        }
    }

    return true;
}


bool
is_digraphic(
    const std::vector<size_t> &in_deg_seq,
    const std::vector<size_t> &out_deg_seq,
    bool is_sorted
)
{
    if (in_deg_seq.size() != out_deg_seq.size())
    {
        return false;
    }

    typedef std::pair<size_t, size_t> deg_pair;
    std::vector<deg_pair> sorted(in_deg_seq.size());
    size_t in_deg_sum = 0, out_deg_sum = 0;

    for (size_t i = 0; i < in_deg_seq.size(); i++)
    {
        sorted[i] = std::make_pair(in_deg_seq[i], out_deg_seq[i]);
        in_deg_sum += in_deg_seq[i];
        out_deg_sum += out_deg_seq[i];
    }

    if (in_deg_sum != out_deg_sum) // the first condition of the Fulkerson-Chen-Anstee theorem
    {
        return false;
    }

    if (!is_sorted)
    {
        std::sort(sorted.begin(), sorted.end(), std::greater<>());
    }

    for (size_t k = 1, left_side = 0; k < in_deg_seq.size(); k++)
    {
        left_side += sorted[k-1].first;
        size_t right_side = 0;

        for (size_t i = 0; i < k; i++)
        {
            right_side += std::min(k - 1, sorted[i].second);
        }

        for (size_t i = k; i < in_deg_seq.size(); i++)
        {
            right_side += std::min(k, sorted[i].second);
        }

        if (left_side > right_side)
        {
            return false;
        }
    }

    return true;
}


void
eliminate_vertex
(
    size_t v_ind,
    std::set<size_t> &v_forbidden_vertices,
    std::set<size_t> &left_vertices,
    std::set<size_t> &left_vertices_impacted,
    DegreesOfFreedom &v_df,
    DegreesOfFreedom &impacted_df
)
{
    v_df.setToMax(v_ind);
    left_vertices.erase(v_ind);
    std::vector<size_t> impacted_ind;
    std::set_difference(left_vertices_impacted.begin(), left_vertices_impacted.end(),
                        v_forbidden_vertices.begin(), v_forbidden_vertices.end(),
                        std::back_inserter(impacted_ind));

    for (auto ind : impacted_ind)
    {
        impacted_df.decrease(ind);
    }
}

void
decrease_degree(
    size_t v_ind,
    size_t peer_ind,
    std::set<size_t> &v_forbidden_vertices,
    std::vector<size_t> &left_stubs,
    std::set<size_t> &left_vertices,
    std::set<size_t> &left_vertices_impacted,
    DegreesOfFreedom &v_df,
    DegreesOfFreedom &impacted_df
)
{
    v_forbidden_vertices.insert(peer_ind);
    left_stubs[v_ind]--;

    if (left_stubs[v_ind] == 0)
    {
        eliminate_vertex(v_ind, v_forbidden_vertices, left_vertices, left_vertices_impacted, v_df, impacted_df);
    }
}

template<typename EDGES>
void
_from_degree_sequence(
    const std::vector<size_t> &deg_seq,
    const std::vector<std::shared_ptr<Vertex>> &vertices,
    EDGES *edges
)
{
    std::vector<size_t> left_stubs(deg_seq);
    std::set<size_t> left_vertices;
    std::unordered_map<size_t, std::set<size_t>> forbidden_vertices;

    for (size_t i = 0; i < deg_seq.size(); i++)
    {
        if (deg_seq[i] > 0)
        {
            left_vertices.insert(i);
            forbidden_vertices[i].insert(i);
        }
    }

    size_t edges_count = std::accumulate(deg_seq.begin(), deg_seq.end(), 0) / 2;
    DegreesOfFreedom df(deg_seq, deg_seq, left_vertices.size());

    for (size_t i = 0; i < edges_count; i++)
    {
        std::vector<size_t> msc_candidates = df.getCandidates();

        if (msc_candidates.empty()) // might happen if the sequence is not graphic
        {
            break;
        }

        size_t msc_ind = msc_candidates[uu::core::irand(msc_candidates.size())];

        std::vector<size_t> allowed_vertices;
        std::set_difference(left_vertices.begin(), left_vertices.end(),
                            forbidden_vertices[msc_ind].begin(), forbidden_vertices[msc_ind].end(),
                            std::back_inserter(allowed_vertices));

        if (allowed_vertices.empty()) // might happen if the sequence is not graphic
        {
            eliminate_vertex(msc_ind, forbidden_vertices[msc_ind], left_vertices, left_vertices, df, df);
            continue;
        }

        size_t peer_ind = allowed_vertices[uu::core::irand(allowed_vertices.size())];
        // g->edges()->add(vertices[msc_ind].get(), vertices[peer_ind].get());
        edges->add(vertices[msc_ind].get(), vertices[peer_ind].get());


        decrease_degree(msc_ind, peer_ind, forbidden_vertices[msc_ind], left_stubs,
                        left_vertices, left_vertices, df, df);
        decrease_degree(peer_ind, msc_ind, forbidden_vertices[peer_ind], left_stubs,
                        left_vertices, left_vertices, df, df);
    }
}

void
from_degree_sequence(
    const std::vector<size_t> &deg_seq,
    const std::vector<std::shared_ptr<Vertex>> &vertices,
    Network *g
)
{
    for (auto v : vertices)
    {
        g->vertices()->add(v);
    }

    _from_degree_sequence(deg_seq, vertices, g->edges());
}


void
edges_from_degree_sequence(
    const std::vector<size_t> &deg_seq,
    const std::vector<std::shared_ptr<Vertex>> &vertices,
    std::unordered_set<Dyad> &edges_set
)
{
    class EdgesSet
    {
    public:
        std::unordered_set<Dyad> *edges_set_ptr;
        EdgesSet(std::unordered_set<Dyad> *edges_set)
        {
            edges_set_ptr = edges_set;
        }

        void add(Vertex *v1, Vertex *v2)
        {
            edges_set_ptr->emplace(Dyad(v1, v2));
        }
    };

    EdgesSet es(&edges_set);
    _from_degree_sequence(deg_seq, vertices, &es);
}

void
from_degree_sequence(
    const std::vector<size_t> &in_deg_seq,
    const std::vector<size_t> &out_deg_seq,
    const std::vector<std::shared_ptr<Vertex>> &vertices,
    Network *g
)
{
    std::unordered_map<EdgeMode, std::vector<size_t>> left_stubs =
    {
        {EdgeMode::IN, std::vector<size_t>(in_deg_seq) },
        {EdgeMode::OUT, std::vector<size_t>(out_deg_seq) }
    };

    for (auto v: vertices)
    {
        g->vertices()->add(v);
    }

    size_t n = in_deg_seq.size();
    std::unordered_map<EdgeMode, std::set<size_t>> left_vertices =
    {
        {EdgeMode::IN, std::set<size_t>() },
        {EdgeMode::OUT, std::set<size_t>() }
    };
    std::unordered_map<EdgeMode, std::unordered_map<size_t, std::set<size_t>>> forbidden_vertices =
    {
        {EdgeMode::IN, std::unordered_map<size_t, std::set<size_t>>() },
        {EdgeMode::OUT, std::unordered_map<size_t, std::set<size_t>>() }
    };

    for (size_t i = 0; i < n; i++)
    {
        if (in_deg_seq[i] > 0)
        {
            left_vertices[EdgeMode::IN].insert(i);
            forbidden_vertices[EdgeMode::IN][i].insert(i);
        }

        if (out_deg_seq[i] > 0)
        {
            left_vertices[EdgeMode::OUT].insert(i);
            forbidden_vertices[EdgeMode::OUT][i].insert(i);
        }
    }

    DegreesOfFreedom idf(in_deg_seq, out_deg_seq, left_vertices[EdgeMode::OUT].size());
    DegreesOfFreedom odf(in_deg_seq, in_deg_seq, left_vertices[EdgeMode::IN].size());
    size_t edges_count = std::accumulate(in_deg_seq.begin(), in_deg_seq.end(), 0);

    for (size_t i = 0; i < edges_count; i++)
    {
        std::vector<size_t> msc_candidates = DegreesOfFreedom::getCandidatesDirectedGraph(idf, odf);
        size_t msc_ind = msc_candidates[uu::core::irand(msc_candidates.size())];
        EdgeMode mode = (odf.get(msc_ind) == odf.getMin()) ? EdgeMode::IN : EdgeMode::OUT; // mode of the stub to be matched

        std::set<size_t> *fv_ptr = &forbidden_vertices[mode][msc_ind];
        std::set<size_t> *ln_ptr = &left_vertices[mode];
        std::vector<size_t> allowed_vertices;
        std::set_difference(ln_ptr->begin(), ln_ptr->end(),
                            fv_ptr->begin(), fv_ptr->end(),
                            std::back_inserter(allowed_vertices));

        size_t peer_ind = allowed_vertices[uu::core::irand(allowed_vertices.size())];
        size_t source = (mode == EdgeMode::IN) ? msc_ind : peer_ind;
        size_t target = (mode == EdgeMode::IN) ? peer_ind : msc_ind;

        g->edges()->add(vertices[source].get(), vertices[target].get());
        decrease_degree(source, target, forbidden_vertices[EdgeMode::IN][source],
                        left_stubs[EdgeMode::OUT], left_vertices[EdgeMode::OUT],
                        left_vertices[EdgeMode::IN], odf, idf);
        decrease_degree(target, source, forbidden_vertices[EdgeMode::OUT][target],
                        left_stubs[EdgeMode::IN], left_vertices[EdgeMode::IN],
                        left_vertices[EdgeMode::OUT], idf, odf);
    }
}


}
}

