#include <iostream>

enum Month {
    January,
    February,
    March,
    April,
    May,
    June,
    July,
    August,
    September,
    October,
    November,
    December
};

// Overloading the prefix ++ operator
Month operator++(Month &month) {
    if (month == December) 
    {
        month = January;
    } else {
        month = (Month)(month + 1); 
    }
    return month;
}

// Overloading the prefix -- operator
Month operator--(Month &month) {
    if (month == January) 
    {
        month = December;
    } else {
        month = (Month)(month - 1); 
    }
    return month;
}

Month operator++(Month &month, int) {
    Month oldMonth = month; 
    operator++(month);  
    return oldMonth;      
}
Month operator--(Month &month, int) {
    Month oldMonth = month;
    operator--(month); 
    return oldMonth;  
}

// Getting the names of the months
const char *getMonthName(Month month) {
    switch (month) {
    case January:
        return "January";
    case February:
        return "February";
    case March:
        return "March";
    case April:
        return "April";
    case May:
        return "May";
    case June:
        return "June";
    case July:
        return "July";
    case August:
        return "August";
    case September:
        return "September";
    case October:
        return "October";
    case November:
        return "November";
    default:
        return "December";
    }
}

int main() {
   
    Month m = January;
    std::cout << "Month: " << getMonthName(m) << std::endl;
    m--;
    std::cout << "Previous month: " << getMonthName(m) << std::endl;

    std::cout << "Month: " << getMonthName(m) << std::endl;
    m++;
    std::cout << "Next month: " << getMonthName(m) << std::endl;

    return 0;
}
