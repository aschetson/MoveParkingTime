#ifndef SOLUTION_H
#define SOLUTION_H

#include <memory>
#include <unordered_map>

#include "idatareader.h"
#include "iresultwriter.h"
#include "result.h"

class TimeRegistrator;

/// Main class
class Solution
{
    /// Object to read log
    std::unique_ptr<IDataReader> m_logReader;
    /// Object to write results
    std::unique_ptr<IResultWriter> m_resultWriter;

    /**
     * @brief Reads data from log and sort it
     * @return Sorted vector of log items
     */
    std::vector<DataItem> readData();

public:
    /**
     * @brief Constructor
     * @param logReader Object to read data from log
     */
    Solution(std::unique_ptr<IDataReader> logReader, std::unique_ptr<IResultWriter> resultWriter);

    /**
     * @brief Main method that reads and process data and save results
     */
    void process();
};


#endif // SOLUTION_H
