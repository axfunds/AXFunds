// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2012 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "assert.h"

#include "chainparams.h"
#include "main.h"
#include "util.h"

#include <boost/assign/list_of.hpp>

using namespace boost::assign;

struct SeedSpec6 {
    uint8_t addr[16];
    uint16_t port;
};

#include "chainparamsseeds.h"

//
// Main network
//

// Convert the pnSeeds6 array into usable address objects.
static void convertSeed6(std::vector<CAddress> &vSeedsOut, const SeedSpec6 *data, unsigned int count)
{
    // It'll only connect to one or two seed nodes because once it connects,
    // it'll get a pile of addresses with newer timestamps.
    // Seed nodes are given a random 'last seen time' of between one and two
    // weeks ago.
    const int64_t nOneWeek = 7*24*60*60;
    for (unsigned int i = 0; i < count; i++)
    {
        struct in6_addr ip;
        memcpy(&ip, data[i].addr, sizeof(ip));
        CAddress addr(CService(ip, data[i].port));
        addr.nTime = GetTime() - GetRand(nOneWeek) - nOneWeek;
        vSeedsOut.push_back(addr);
    }
}

class CMainParams : public CChainParams {
public:
    CMainParams() {
        // The message start string is designed to be unlikely to occur in normal data.
        // The characters are rarely used upper ASCII, not valid as UTF-8, and produce
        // a large 4-byte int at any alignment.
        pchMessageStart[0] = 0x19;
        pchMessageStart[1] = 0x43;
        pchMessageStart[2] = 0x20;
        pchMessageStart[3] = 0x17;
        vAlertPubKey = ParseHex("041f97a158978b88ecafa084610eb007f80fa947bf896eb7046eb4e40c39bb57bd2fd431a9a83c7221f6010cce5d23a5ae789ee5f2a541a95f5212d2ed0eedd814");
        nDefaultPort = 19344;
        nRPCPort = 44391 ;
        bnProofOfWorkLimit = CBigNum(~uint256(0) >> 20);
        

        // Build the genesis block. Note that the output of the genesis coinbase cannot
        // be spent as it did not originally exist in the database.
        //
        //CBlock(hash=000001faef25dec4fbcf906e6242621df2c183bf232f263d0ba5b101911e4563, ver=1, hashPrevBlock=0000000000000000000000000000000000000000000000000000000000000000, hashMerkleRoot=12630d16a97f24b287c8c2594dda5fb98c9e6c70fc61d44191931ea2aa08dc90, nTime=1393221600, nBits=1e0fffff, nNonce=164482, vtx=1, vchBlockSig=)
        //  Coinbase(hash=12630d16a9, nTime=1393221600, ver=1, vin.size=1, vout.size=1, nLockTime=0)
        //    CTxIn(COutPoint(0000000000, 4294967295), coinbase 00012a24323020466562203230313420426974636f696e2041544d7320636f6d6520746f20555341)
        //    CTxOut(empty)
        //  vMerkleTree: 12630d16a9


        const char* pszTimestamp = "A Bitcoin Battle Is Brewing";
        std::vector<CTxIn> vin;
        vin.resize(1);
        vin[0].scriptSig = CScript() << 0 << CBigNum(42) << vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));
        std::vector<CTxOut> vout;
        vout.resize(1);
        vout[0].SetEmpty();
        CTransaction txNew(1, 1417912409, vin, vout, 0);
        genesis.vtx.push_back(txNew);
        genesis.hashPrevBlock = 0;
        genesis.hashMerkleRoot = genesis.BuildMerkleTree();
        genesis.nVersion = 1;
        genesis.nTime    = 1417912409;
        genesis.nBits    = bnProofOfWorkLimit.GetCompact();
        genesis.nNonce   = 21100558;

        hashGenesisBlock = genesis.GetHash();
        // printf ("hashGenesisBlock:%s hashMerkleRoot:%s\n",hashGenesisBlock.ToString().c_str(),genesis.hashMerkleRoot.ToString().c_str());


        assert(hashGenesisBlock == uint256("52a542862f874c62249c3ccca99ad6170344686a5f350ffde5b3fd7cf7081fdd"));
        assert(genesis.hashMerkleRoot == uint256("b746b69f230fc846846f232bd5d496d8ac405238d5b919a749835f3938a67dcd"));


        vSeeds.push_back(CDNSSeedData("seed.quadrigacx.pro","seed.quadrigacx.pro"));
        vSeeds.push_back(CDNSSeedData("seed.quadrigacx.pro:1944","seed.quadrigacx.pro:1944"));
        vSeeds.push_back(CDNSSeedData("seed1.quadrigacx.pro","seed1.quadrigacx.pro"));
        vSeeds.push_back(CDNSSeedData("seed2.quadrigacx.pro","seed2.quadrigacx.pro"));
        vSeeds.push_back(CDNSSeedData("seed3.quadrigacx.pro","seed3.quadrigacx.pro"));
        vSeeds.push_back(CDNSSeedData("seed4.quadrigacx.pro","seed4.quadrigacx.pro"));
        vSeeds.push_back(CDNSSeedData("seed5.quadrigacx.pro","seed5.quadrigacx.pro"));        
        vSeeds.push_back(CDNSSeedData("dnsseed.axfunds.com", "dnsseed.axfunds.com"));
        vSeeds.push_back(CDNSSeedData("axfunds.com", "seed.axfunds.com"));
        vSeeds.push_back(CDNSSeedData("117.41.187.53","117.41.187.53"));
        vSeeds.push_back(CDNSSeedData("211.149.241.6","211.149.241.6"));
        vSeeds.push_back(CDNSSeedData("211.149.226.228","211.149.226.228"));
        vSeeds.push_back(CDNSSeedData("211.149.177.209","211.149.177.209"));
        vSeeds.push_back(CDNSSeedData("",""));

        vSeeds.push_back(CDNSSeedData("106.187.39.23", "106.187.39.23"));
        vSeeds.push_back(CDNSSeedData("106.187.39.23:19344","106.187.39.23:19344"));
        vSeeds.push_back(CDNSSeedData("125.69.76.248","125.69.76.248"));
        vSeeds.push_back(CDNSSeedData("125.69.76.248:19344","125.69.76.248:19344"));
        vSeeds.push_back(CDNSSeedData("108.61.191.77","108.61.191.77"));
        vSeeds.push_back(CDNSSeedData("108.61.191.77:19344","108.61.191.77:19344"));
        vSeeds.push_back(CDNSSeedData("",""));
        




        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 23);
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 85);
        base58Prefixes[SECRET_KEY] =     std::vector<unsigned char>(1, 153);
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x04)(0x88)(0xB2)(0x1E).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x04)(0x88)(0xAD)(0xE4).convert_to_container<std::vector<unsigned char> >();

        convertSeed6(vFixedSeeds, pnSeed6_main, ARRAYLEN(pnSeed6_main));

        nLastPOWBlock = 36;
    }

    virtual const CBlock& GenesisBlock() const { return genesis; }
    virtual Network NetworkID() const { return CChainParams::MAIN; }

    virtual const vector<CAddress>& FixedSeeds() const {
        return vFixedSeeds;
    }
protected:
    CBlock genesis;
    vector<CAddress> vFixedSeeds;
};
static CMainParams mainParams;


//
// Testnet
//

class CTestNetParams : public CMainParams {
public:
    CTestNetParams() {
        // The message start string is designed to be unlikely to occur in normal data.
        // The characters are rarely used upper ASCII, not valid as UTF-8, and produce
        // a large 4-byte int at any alignment.
        pchMessageStart[0] = 0xcd;
        pchMessageStart[1] = 0xf2;
        pchMessageStart[2] = 0xc0;
        pchMessageStart[3] = 0xef;
        bnProofOfWorkLimit = CBigNum(~uint256(0) >> 16);
        vAlertPubKey = ParseHex("0471dc165db490094d35cde15b1f5d755fa6ad6f2b5ed0f340e3f17f57389c3c2af113a8cbcc885bde73305a553b5640c83021128008ddf882e856336269080496");
        nDefaultPort = 25714;
        nRPCPort = 25715;
        strDataDir = "testnet";

        // Modify the testnet genesis block so the timestamp is valid for a later start.
        genesis.nBits  = bnProofOfWorkLimit.GetCompact();
        genesis.nNonce = 216178;
        hashGenesisBlock = genesis.GetHash();
        // printf ("hashGenesisBlock:%s hashMerkleRoot:%s\n",hashGenesisBlock.ToString().c_str(),genesis.hashMerkleRoot.ToString().c_str());
        assert(hashGenesisBlock == uint256("d73216a49298e7451de5d5243b1c80b7961c89c91d2579817580fe23cb3e1bc6"));

        vFixedSeeds.clear();
        vSeeds.clear();

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 111);
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 196);
        base58Prefixes[SECRET_KEY]     = std::vector<unsigned char>(1, 239);
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x04)(0x35)(0x87)(0xCF).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x04)(0x35)(0x83)(0x94).convert_to_container<std::vector<unsigned char> >();

        convertSeed6(vFixedSeeds, pnSeed6_test, ARRAYLEN(pnSeed6_test));

        nLastPOWBlock = 0x7fffffff;
    }
    virtual Network NetworkID() const { return CChainParams::TESTNET; }
};
static CTestNetParams testNetParams;


//
// Regression test
//
class CRegTestParams : public CTestNetParams {
public:
    CRegTestParams() {
        pchMessageStart[0] = 0xfa;
        pchMessageStart[1] = 0xbf;
        pchMessageStart[2] = 0xb5;
        pchMessageStart[3] = 0xda;
        bnProofOfWorkLimit = CBigNum(~uint256(0) >> 1);
        genesis.nTime = 1411111111;
        genesis.nBits  = bnProofOfWorkLimit.GetCompact();
        genesis.nNonce = 2;
        hashGenesisBlock = genesis.GetHash();
        nDefaultPort = 18444;
        strDataDir = "regtest";
        // printf ("hashGenesisBlock:%s hashMerkleRoot:%s\n",hashGenesisBlock.ToString().c_str(),genesis.hashMerkleRoot.ToString().c_str());
        assert(hashGenesisBlock == uint256("81b3c155edfec14dc52a3236cc3a029abdeab1cab0aac03e6399137d350c0cb2"));

        vSeeds.clear();  // Regtest mode doesn't have any DNS seeds.
    }

    virtual bool RequireRPCPassword() const { return false; }
    virtual Network NetworkID() const { return CChainParams::REGTEST; }
};
static CRegTestParams regTestParams;

static CChainParams *pCurrentParams = &mainParams;

const CChainParams &Params() {
    return *pCurrentParams;
}

void SelectParams(CChainParams::Network network) {
    switch (network) {
        case CChainParams::MAIN:
            pCurrentParams = &mainParams;
            break;
        case CChainParams::TESTNET:
            pCurrentParams = &testNetParams;
            break;
        case CChainParams::REGTEST:
            pCurrentParams = &regTestParams;
            break;
        default:
            assert(false && "Unimplemented network");
            return;
    }
}

bool SelectParamsFromCommandLine() {
    bool fRegTest = GetBoolArg("-regtest", false);
    bool fTestNet = GetBoolArg("-testnet", false);

    if (fTestNet && fRegTest) {
        return false;
    }

    if (fRegTest) {
        SelectParams(CChainParams::REGTEST);
    } else if (fTestNet) {
        SelectParams(CChainParams::TESTNET);
    } else {
        SelectParams(CChainParams::MAIN);
    }
    return true;
}
