#ifndef UUNET_GENERATION_IMPL_DEGREESOFFREEDOM_H
#define UUNET_GENERATION_IMPL_DEGREESOFFREEDOM_H

class DegreesOfFreedom
{
public:
    DegreesOfFreedom(
            const std::vector<size_t> &deg_seq,
            const std::vector<size_t> &remaining_stubs,
            size_t available_stubs
    )
    {
        size_t n = deg_seq.size();
        df_.resize(n);

        for (size_t i = 0; i < n; i++)
        {
            size_t cn_count = available_stubs - (deg_seq[i] > 0); // candidate vertices count
            df_[i] = (deg_seq[i] == 0) ? kMAX_ : cn_count - std::min(remaining_stubs[i], cn_count);
        }
    };

    size_t
    decrease(
            size_t ind
    )
    {
        if (df_[ind] == kMAX_ || df_[ind] == 0)
        {
            return df_[ind];
        }

        df_[ind]--;

        if (df_[ind] == current_min_)
        {
            candidates_.emplace(ind);
        }

        else if (df_[ind] < current_min_)
        {
            candidates_ = std::set<size_t>({ind});
            current_min_ = df_[ind];
        }

        return df_[ind];
    };

    void
    setToMax(
            size_t ind
    )
    {
        df_[ind] = kMAX_;
        candidates_.erase(ind);
    };

    size_t
    get(
            size_t ind
    )
    {
        return df_[ind];
    }

    size_t
    getMin(
    )
    {
        if (candidates_.empty())
        {
            recomputeCandidates_();
        }

        return current_min_;
    }

    std::vector<size_t>
    getCandidates(
    )
    {
        if (candidates_.empty())
        {
            recomputeCandidates_();
        }

        return std::vector<size_t>(candidates_.begin(), candidates_.end());
    };

    static std::vector<size_t>
    getCandidatesDirectedGraph(
            DegreesOfFreedom &idf,
            DegreesOfFreedom &odf
    );

private:
    const size_t kMAX_ = std::numeric_limits<size_t>::max();
    std::vector<size_t> df_;
    std::set<size_t> candidates_;
    size_t current_min_ = kMAX_;

    void
    recomputeCandidates_(
    )
    {
        current_min_ = *std::min_element(df_.begin(), df_.end());

        if (current_min_ == kMAX_)
        {
            candidates_ = std::set<size_t>();
            return;
        }

        for (size_t i = 0; i < df_.size(); i++)
        {
            if (df_[i] == current_min_)
            {
                candidates_.insert(i);
            }
        }
    }
};

std::vector<size_t>
DegreesOfFreedom::getCandidatesDirectedGraph(
        DegreesOfFreedom &idf,
        DegreesOfFreedom &odf
)
{
    if (idf.getMin() < odf.getMin())
    {
        return idf.getCandidates();
    }

    if (idf.getMin() > odf.getMin())
    {
        return odf.getCandidates();
    }

    // otherwise candidates must be combined
    std::vector<size_t> candidates = idf.getCandidates();
    std::vector<size_t> candidates_odf = odf.getCandidates();
    candidates.insert(candidates.end(), candidates_odf.begin(), candidates_odf.end());
    return candidates;
};

#endif
