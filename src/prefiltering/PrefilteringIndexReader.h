#ifndef PREFILTERINGINDEXREADER_H
#define PREFILTERINGINDEXREADER_H

#include "IndexTable.h"
#include "DBReader.h"
#include <string>


struct PrefilteringIndexData {
    int kmerSize;
    int alphabetSize;
    int maskResidues;
    int split;
    int local;
    int spacedKmer;
};


class PrefilteringIndexReader {
public:
    static const char*  CURRENT_VERSION;
    static unsigned int VERSION;
    static unsigned int ENTRIES;
    static unsigned int ENTRIESOFFSETS;
    static unsigned int SEQINDEXDATA;
    static unsigned int SEQINDEXDATASIZE;
    static unsigned int SEQINDEXSEQOFFSET;
    static unsigned int ENTRIESNUM;
    static unsigned int SEQCOUNT;
    static unsigned int META;
    static unsigned int SCOREMATRIXNAME;
    static unsigned int SCOREMATRIX3MER;
    static unsigned int DBRINDEX;

    static bool checkIfIndexFile(DBReader<unsigned int> *reader);

    static void createIndexFile(std::string outDb, DBReader<unsigned int> *dbr,
                                BaseMatrix * subMat, int maxSeqLen, bool spacedKmer,
                                bool compBiasCorrection, int split, int alphabetSize, int kmerSize,
                                bool diagonalScoring, bool maskResidues, int threads);

    static DBReader<unsigned int> *openNewReader(DBReader<unsigned int> *dbr);

    static SequenceLookup *getSequenceLookup(DBReader<unsigned int> *dbr, int split);

    static IndexTable *generateIndexTable(DBReader<unsigned int> *dbr, int split, bool diagonalScoring);

    static PrefilteringIndexData getMetadata(DBReader<unsigned int> *dbr);

    static std::string getSubstitutionMatrixName(DBReader<unsigned int> *dbr);

    static ScoreMatrix *get3MerScoreMatrix(DBReader<unsigned int> *dbr);

    static std::string searchForIndex(const std::string &pathToDB);
};

#endif
