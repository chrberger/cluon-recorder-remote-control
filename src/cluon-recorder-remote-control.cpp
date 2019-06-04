/*
 * Copyright (C) 2019  Christian Berger
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "cluon-complete.hpp"

#include <chrono>
#include <iostream>
#include <thread>

int32_t main(int32_t argc, char **argv) {
    int32_t retCode{0};
    auto commandlineArguments = cluon::getCommandlineArguments(argc, argv);
    if ( (0 == commandlineArguments.count("cid")) ||
         ( (0 == commandlineArguments.count("start")) && (0 == commandlineArguments.count("stop"))) ||
         ( (1 == commandlineArguments.count("start")) && (1 == commandlineArguments.count("stop")))
       ) {
        std::cerr << argv[0] << " starts or stops a remotely running recording session for a given CID." << std::endl;
        std::cerr << "Usage:   " << argv[0] << " --cid=<OpenDaVINCI session to record Envelopes>] [--rec=MyFile.rec] [--recsuffix=Suffix] [--remote]" << std::endl;
        std::cerr << "         --cid:     CID of the OD4Session to receive Envelopes for recording" << std::endl;
        std::cerr << "         --start:   send the command to start the recording" << std::endl;
        std::cerr << "         --stop:    send the command to stop the recording" << std::endl;
        std::cerr << "Example: " << argv[0] << " --cid=111 --start" << std::endl;
        retCode = 1;
    } else {
        const bool START{commandlineArguments.count("start") != 0};

        // Interface to a running OpenDaVINCI session (ignoring any incoming Envelopes).
        cluon::OD4Session od4(static_cast<uint16_t>(std::stoi(commandlineArguments["cid"])));
        {
            using namespace std::literals::chrono_literals; // NOLINT
            std::this_thread::sleep_for(1s);
        }
        cluon::data::RecorderCommand rc;
        rc.command( START ? 1 : 2 );
        od4.send(rc);
        {
            using namespace std::literals::chrono_literals; // NOLINT
            std::this_thread::sleep_for(1s);
        }
    }
    return retCode;
}

