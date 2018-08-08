#ifndef TSP_FINAL_REPORT_HPP
#define TSP_FINAL_REPORT_HPP

#include <string>
#include <iostream>
#include <optional>
#include <vector>

struct Point;

class Report
{
public:
    Report(const std::optional<std::string> &, bool);
    void generateReport(const std::vector<double> &, const std::vector<Point> &, double, int) const;
private:
    void
    saveOrPrintFile(std::ostream &output, const std::vector<double> &, const std::vector<Point> &, double, int) const;
    bool isVerbose{};
    std::optional<std::string> pathToFile{};
};


#endif //TSP_FINAL_REPORT_HPP
