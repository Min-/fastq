//
//  test_read.cpp
//  fastq
//
//  Created by Min Zhang on 2020/5/9.
//  Copyright © 2020 Min Zhang. All rights reserved.
//

#include <stdio.h>

#include "read.h"
#include "fastqreader.h"
#include "stats.h"

int main(){
    std::string R1_path = "/Users/min/dev/fastq/fastq/R1.fq";
    FastqReader R1 = FastqReader(R1_path);
    
    bool reachEOF = false;
    while(!reachEOF){
        Read* r = R1.read();
        if(!r){
            reachEOF = true;
            break;
        }
        
        r->print();
        std::cout << "last index: " << r->lastIndex() << std::endl;
        std::cout << "first index: " << r->firstIndex() << std::endl;
        std::cout << "low qual count: " << r->lowQualCount() << std::endl;
        
        
    }
    
    return 0;
}
