#!/usr/bin/env python3
# Copyright (c) 2015-2016 The Bitcoin Core developers

# This program is free software: you can redistribute it and/or modify\n# it under the terms of the GNU General Public License as published by\n# the Free Software Foundation, either version 3 of the License, or\n# (at your option) any later version.\n\n# This program is distributed in the hope that it will be useful,\n# but WITHOUT ANY WARRANTY; without even the implied warranty of\n# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the \n# GNU General Public License for more details.\n\n# You should have received a copy of the GNU General Public License\n# along with this program. If not, see <http://www.gnu.org/licenses/>.#

#
# Test mulitple rpc user config option rpcauth
#

from test_framework.test_framework import IoPTestFramework
from test_framework.util import str_to_b64str, assert_equal

import os
import http.client
import urllib.parse

class HTTPBasicsTest (IoPTestFramework):

    def __init__(self):
        super().__init__()
        self.setup_clean_chain = False
        self.num_nodes = 1

    def setup_chain(self):
        super().setup_chain()
        #Append rpcauth to IoP.conf before initialization
        rpcauth = "rpcauth=rt:93648e835a54c573682c2eb19f882535$7681e9c5b74bdd85e78166031d2058e1069b3ed7ed967c93fc63abba06f31144"
        rpcauth2 = "rpcauth=rt2:f8607b1a88861fac29dfccf9b52ff9f$ff36a0c23c8c62b4846112e50fa888416e94c17bfd4c42f88fd8f55ec6a3137e"
        with open(os.path.join(self.options.tmpdir+"/node0", "IoP.conf"), 'a') as f:
            f.write(rpcauth+"\n")
            f.write(rpcauth2+"\n")

    def setup_network(self):
        self.nodes = self.setup_nodes()

    def run_test(self):

        ##################################################
        # Check correctness of the rpcauth config option #
        ##################################################
        url = urllib.parse.urlparse(self.nodes[0].url)

        #Old authpair
        authpair = url.username + ':' + url.password

        #New authpair generated via share/rpcuser tool
        rpcauth = "rpcauth=rt:93648e835a54c573682c2eb19f882535$7681e9c5b74bdd85e78166031d2058e1069b3ed7ed967c93fc63abba06f31144"
        password = "cA773lm788buwYe4g4WT+05pKyNruVKjQ25x3n0DQcM="

        #Second authpair with different username
        rpcauth2 = "rpcauth=rt2:f8607b1a88861fac29dfccf9b52ff9f$ff36a0c23c8c62b4846112e50fa888416e94c17bfd4c42f88fd8f55ec6a3137e"
        password2 = "8/F3uMDw4KSEbw96U3CA1C4X05dkHDN2BPFjTgZW4KI="
        authpairnew = "rt:"+password

        headers = {"Authorization": "Basic " + str_to_b64str(authpair)}

        conn = http.client.HTTPConnection(url.hostname, url.port)
        conn.connect()
        conn.request('POST', '/', '{"method": "getbestblockhash"}', headers)
        resp = conn.getresponse()
        assert_equal(resp.status==401, False)
        conn.close()

        #Use new authpair to confirm both work
        headers = {"Authorization": "Basic " + str_to_b64str(authpairnew)}

        conn = http.client.HTTPConnection(url.hostname, url.port)
        conn.connect()
        conn.request('POST', '/', '{"method": "getbestblockhash"}', headers)
        resp = conn.getresponse()
        assert_equal(resp.status==401, False)
        conn.close()

        #Wrong login name with rt's password
        authpairnew = "rtwrong:"+password
        headers = {"Authorization": "Basic " + str_to_b64str(authpairnew)}

        conn = http.client.HTTPConnection(url.hostname, url.port)
        conn.connect()
        conn.request('POST', '/', '{"method": "getbestblockhash"}', headers)
        resp = conn.getresponse()
        assert_equal(resp.status==401, True)
        conn.close()

        #Wrong password for rt
        authpairnew = "rt:"+password+"wrong"
        headers = {"Authorization": "Basic " + str_to_b64str(authpairnew)}

        conn = http.client.HTTPConnection(url.hostname, url.port)
        conn.connect()
        conn.request('POST', '/', '{"method": "getbestblockhash"}', headers)
        resp = conn.getresponse()
        assert_equal(resp.status==401, True)
        conn.close()

        #Correct for rt2
        authpairnew = "rt2:"+password2
        headers = {"Authorization": "Basic " + str_to_b64str(authpairnew)}

        conn = http.client.HTTPConnection(url.hostname, url.port)
        conn.connect()
        conn.request('POST', '/', '{"method": "getbestblockhash"}', headers)
        resp = conn.getresponse()
        assert_equal(resp.status==401, False)
        conn.close()

        #Wrong password for rt2
        authpairnew = "rt2:"+password2+"wrong"
        headers = {"Authorization": "Basic " + str_to_b64str(authpairnew)}

        conn = http.client.HTTPConnection(url.hostname, url.port)
        conn.connect()
        conn.request('POST', '/', '{"method": "getbestblockhash"}', headers)
        resp = conn.getresponse()
        assert_equal(resp.status==401, True)
        conn.close()


if __name__ == '__main__':
    HTTPBasicsTest ().main ()
