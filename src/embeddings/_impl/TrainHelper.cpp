/**
 * @file
 * @brief
 * @author Max Fomichev
 * @date 15.02.2017
 * @copyright Apache License v.2 (http://www.apache.org/licenses/LICENSE-2.0)
*/
#include "TrainHelper.hpp"

namespace uu
{
    namespace net
    {

        w2v::w2vModel_t train_w2v(std::string trainFile, std::string modelFile, w2v::trainSettings_t trainSettings)
        {

            std::string stopWordsFile;
            bool verbose = true;

            if (verbose)
            {
                std::cout << "Train data file: " << trainFile << std::endl;
                std::cout << "Output model file: " << modelFile << std::endl;
                std::cout << "Stop-words file: " << stopWordsFile << std::endl;
                std::cout << "Training model: " << (trainSettings.withSG ? "Skip-Gram" : "CBOW") << std::endl;
                std::cout << "Sample approximation method: ";
                if (trainSettings.withHS)
                {
                    std::cout << "Hierarchical softmax" << std::endl;
                }
                else
                {
                    std::cout << "Negative sampling with number of negative examples = "
                              << static_cast<int>(trainSettings.negative) << std::endl;
                }
                std::cout << "Number of training threads: " << static_cast<int>(trainSettings.threads) << std::endl;
                std::cout << "Number of training iterations: " << static_cast<int>(trainSettings.iterations) << std::endl;
                std::cout << "Min word frequency: " << static_cast<int>(trainSettings.minWordFreq) << std::endl;
                std::cout << "Vector size: " << static_cast<int>(trainSettings.size) << std::endl;
                std::cout << "Max skip length: " << static_cast<int>(trainSettings.window) << std::endl;
                std::cout << "Threshold for occurrence of words: " << trainSettings.sample << std::endl;
                std::cout << "Starting learning rate: " << trainSettings.alpha << std::endl;
                std::cout << std::endl
                          << std::flush;
            }

            w2v::w2vModel_t model;
            bool trained;
            if (verbose)
            {
                trained = model.train(
                    trainSettings, trainFile, stopWordsFile,
                    [](float _percent) {
                        std::cout << "\rParsing train data... "
                                  << std::fixed << std::setprecision(2)
                                  << _percent << "%" << std::flush;
                    },
                    [](std::size_t _vocWords, std::size_t _trainWords, std::size_t _totalWords) {
                        std::cout << std::endl
                                  << "Vocabulary size: " << _vocWords << std::endl
                                  << "Train words: " << _trainWords << std::endl
                                  << "Total words: " << _totalWords << std::endl
                                  << std::endl;
                    },
                    [](float _alpha, float _percent) {
                        std::cout << '\r'
                                  << "alpha: "
                                  << std::fixed << std::setprecision(6)
                                  << _alpha
                                  << ", progress: "
                                  << std::fixed << std::setprecision(2)
                                  << _percent << "%"
                                  << std::flush;
                    });
                std::cout << std::endl;
            }
            else
            {
                trained = model.train(trainSettings, trainFile, stopWordsFile, nullptr, nullptr, nullptr);
            }
            if (!trained)
            {
                std::cerr << "Training failed: " << model.errMsg() << std::endl;
                return model;
            }

            return model;
        }
    } // namespace net
} // namespace uu