//
//  read_main.cpp
//  fastq
//
//  Created by Min Zhang on 2020/5/9.
//  Copyright © 2020 Min Zhang. All rights reserved.
//

#include <stdio.h>
#include <string>
#include "read.h"
#include "fastqreader.h"

int main__check_fastq(){
    std::string R1_path = "/Users/min/dev/fastq/fastq/R1.fq";
    FastqReader R1 = FastqReader(R1_path);
    
    Read* r1;
    r1 = R1.read();
    r1->print();
    
    std::cout << sizeof(r1) << std::endl;
    
// read through fastq file
    long records = 0;
    bool reachedEOF = false;

    // get seqlen
    int seqlen=0;
    int totallen=0;
    while(records < 1000) {
        Read* r = R1.read();
        if(!r) {
            reachedEOF = true;
            break;
        }
        int rlen = r->length();
        totallen+=rlen;
        if(rlen > seqlen)
            seqlen = rlen;
        records ++;
        r->print();
        std::cout << "read: " << records << std::endl;
        delete r; // destroy the read right away
    }

    std::cout << seqlen << std::endl;
    std::cout << "average read length: " << totallen/records << std::endl;
    
    return 0;
}
