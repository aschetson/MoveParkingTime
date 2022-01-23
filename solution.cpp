#include "solution.h"

#include "timeregistrator.h"
#include "result.h"


std::vector<DataItem> Solution::readData()
{
    std::vector<DataItem> vec;

    while (!m_logReader->atEnd())
    {
        // TODO: check if we need to handle error here

        // we can catch here format error to continue reading until end
//        try
//        {
            vec.push_back(m_logReader->readNext());
//        }
//        catch (InvalidData& e)
//        {
//            showErrorToUser();
//        }
    }

    std::sort(vec.begin(), vec.end(), [](const DataItem& left, const DataItem& right)
    {
        return left.dateTime < right.dateTime;
    });

    return vec;
}

Solution::Solution(std::unique_ptr<IDataReader> logReader, std::unique_ptr<IResultWriter> resultWriter)
    : m_logReader(std::move(logReader))
    , m_resultWriter(std::move(resultWriter))
{
}

void Solution::process()
{
    // one TimeRegistrator for every vehicle
    std::unordered_map<std::string, std::shared_ptr<TimeRegistrator>> res;

    for (const auto& item : readData())
    {
        try
        {
            res.at(item.id.toStdString())->addData(item.speed, item.dateTime.time());
        }
        catch (std::out_of_range&)
        {
            std::shared_ptr<TimeRegistrator> registrator = std::make_shared<TimeRegistrator>();
            registrator->addData(item.speed, item.dateTime.time());
            res.insert({item.id.toStdString(), registrator});
        }
    }

    for (const auto& item : res)
    {
        item.second->flush();
        m_resultWriter->write({item.first, item.second->timeParked(), item.second->timeMoved()});
    }
}
