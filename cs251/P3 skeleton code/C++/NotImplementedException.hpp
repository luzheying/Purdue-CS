//
//  NotImplementedException.hpp
//  
//
//  Created by Wenjie Bai on 2/7/19.
//

#ifndef NotImplementedException_hpp
#define NotImplementedException_hpp

#include <stdio.h>

class NotImplementedException{
    public:
        NotImplementedException(const string& err) : errMsg(err) { }
        string getError() { return errMsg; } 
    private:
        string errMsg;
};
#endif /* NotImplementedException_hpp */
