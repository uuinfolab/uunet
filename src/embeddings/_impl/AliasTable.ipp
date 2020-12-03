namespace uu
{
    namespace net
    {
            template<typename ObjType>
            AliasTable<ObjType>::AliasTable(std::vector<double> probabilities, std::vector<const ObjType *> _objects)
            {
                objects = _objects;
                int num_of_elements = probabilities.size();
                prob_table = std::vector<double>(num_of_elements);
                alias_table = std::vector<int>(num_of_elements);
                for (int i = 0; i < num_of_elements; ++i)
                {
                    prob_table[i] = probabilities[i] * num_of_elements;
                }
                std::vector<int> over_full = std::vector<int>();
                std::vector<int> under_full = std::vector<int>();
                std::vector<int> exactly_full = std::vector<int>();
                int non_exactly_full = 0;
                for (int i = 0; i < num_of_elements; ++i)
                {
                    if (prob_table[i] > 1)
                    {
                        over_full.push_back(i);
                        non_exactly_full++;
                    }
                    else if (prob_table[i] < 1)
                    {
                        under_full.push_back(i);
                        non_exactly_full++;
                    }
                    else
                    {
                        exactly_full.push_back(i); //question about if = 1 will really work
                    }
                }
                int index_under = 0;
                int index_over = 0;
                while (over_full.size() != 0 && under_full.size() != 0)
                {
                    index_under = under_full.back();
                    index_over = over_full.back();
                    under_full.pop_back();
                    over_full.pop_back();
                    alias_table[index_under] = index_over;
                    prob_table[index_over] += prob_table[index_under] - 1;
                    if (prob_table[index_over] > 1)
                    {
                        over_full.push_back(index_over);
                        non_exactly_full++;
                    }

                    else if (prob_table[index_over] < 1)
                    {
                        under_full.push_back(index_over);
                        non_exactly_full++;
                    }
                    else
                    {
                        exactly_full.push_back(index_over);
                    }
                }
                if (over_full.size() != 0)
                {
                    for (auto i : over_full)
                    {
                        prob_table[i] = 1;
                    }
                }
                if (under_full.size() != 0)
                {
                    for (auto i : under_full)
                    {
                        prob_table[i] = 1;
                    }
                }
            }
            template <typename ObjType>
            const ObjType * AliasTable<ObjType>::alias_sampling(std::default_random_engine *generator)
            {
                std::uniform_real_distribution<double> distribution(0.0, 1.0);
                double x = distribution(*generator);
                int i = floor(alias_table.size() * x);
                double y = alias_table.size() * x - i;
                if (y < prob_table[i])
                {
                    return objects[i];
                }
                else
                {
                    return objects[alias_table[i]];
                }
            }
            template <typename ObjType>
            int AliasTable<ObjType>::size(){return prob_table.size();}
    } // namespace net
} // namespace uu
