
#include "Person.h"
#include "Thing.h"
#include "Record.h"

int main(){
    
    GPS_DD Room_176_Everson_Hall {"Room 176 Everson Hall",38.53885934658859, -121.75019324718353};
    GPS_DD Silo_Station {"SiloStation",38.53928632318267, -121.75312951094764};
    GPS_DD i8th_and_J_Street {"8th and J Street",38.5519996150439, -121.73897431778535};
    GPS_DD Moore_and_Pollock_Stop {"Moore and Pollock Stop",38.56454280609437, -121.71909290115407};

    JvTime jv_time1(2023, 4, 12, 18, 00, 0);
    std::string time_18_00_pm = jv_time1.get12HourTimeString();
    Person instructor {"The instructor", Room_176_Everson_Hall};
    instructor.setLocation(Room_176_Everson_Hall, time_18_00_pm/*6:00pm*/);
    Thing nothing {instructor};
    nothing.stuff = "";
    
    Json::Value x;
    Record r1 {instructor, nothing, Room_176_Everson_Hall, time_18_00_pm};
    x = r1.dump2JSON();
    std::cout << x.toStyledString() << std::endl;

    Thing l_line {instructor};
    l_line.type = "Bus";
    l_line.stuff = "Unitarians L line";
    l_line.location = Silo_Station;
    JvTime jv_time2(2023, 4, 12, 18, 10, 0);
    std::string time_18_10_pm = jv_time2.get12HourTimeString();


    Person bus_driver {"Bus driver", "Tiffany", l_line.location};
    Person Student_John {"sutdent", "John", l_line.location};
    instructor.setLocation(l_line.location, time_18_10_pm/*6:10pm*/);
    Student_John.setLocation(l_line.location, time_18_10_pm/*6:10pm*/);
    bus_driver.setLocation(l_line.location, time_18_10_pm/*6:10pm*/);

    Thing computer {Student_John};
    computer.type = "Computer";
    computer.stuff = "His own computer";

    Record r2 {instructor,bus_driver,Student_John,l_line,computer,l_line.location,time_18_10_pm};
    x = r2.dump2JSON();
    std::cout << x.toStyledString() << std::endl; 

    JvTime jv_time3(2023, 4, 12, 18, 20, 0);
    std::string time_18_20_pm = jv_time3.get12HourTimeString();
    l_line.location = i8th_and_J_Street;

    Student_John.setLocation(i8th_and_J_Street, time_18_20_pm/*6:20pm*/);
    bus_driver.setLocation(l_line.location, time_18_20_pm/*6:20pm*/);
    instructor.setLocation(l_line.location, time_18_20_pm/*6:20pm*/);
    
    Thing Android_device {instructor};
    Android_device.type = "Device";
    Android_device.stuff = "Android device"; 

    Record r3 {instructor,bus_driver,l_line,Android_device,l_line.location,time_18_20_pm};
    x = r3.dump2JSON();
    std::cout << x.toStyledString() << std::endl; 
    JvTime jv_time4(2023, 4, 12, 18, 32, 0);
    std::string time_18_32_pm = jv_time4.get12HourTimeString();
    l_line.location = Moore_and_Pollock_Stop;

    instructor.setLocation(Moore_and_Pollock_Stop, time_18_32_pm/*6:32pm*/);
    bus_driver.setLocation(l_line.location, time_18_32_pm/*6:32pm*/);

    Record r4 {instructor, Android_device, Moore_and_Pollock_Stop,time_18_32_pm};
    x = r4.dump2JSON();
    std::cout << x.toStyledString() << std::endl; 

    return 0;

}