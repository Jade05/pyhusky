// Copyright 2016 Husky Team
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <backend/workerdriver.hpp>
#include <backend/daemondriver.hpp>
#include <backend/pythonconnector.hpp>
#include <backend/threadconnector.hpp>

int main(int argc, char ** argv) {
    husky::WorkerDriver::init_worker_instr_handler_map();
    husky::DaemonDriver::init_daemon_handler_map();
    // Register the handlers
    husky::WorkerDriver::register_handler();
    husky::PythonConnector::register_handler();
    husky::ThreadConnector::register_handler();

    // init conf first
    std::vector<std::string> args;
    args.push_back("hdfs_namenode");
    args.push_back("hdfs_namenode_port");
    // args.push_back("train");
    // args.push_back("test");
    args.push_back("n_iter");
    args.push_back("alpha");
    args.push_back("lambda");
    husky::DaemonDriver::daemon_run(argc, argv, args);

    return 0;
}
