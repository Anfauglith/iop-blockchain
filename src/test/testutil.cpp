// Copyright (c) 2009-2016 The Bitcoin Core developers 
// Copyright (c) 2017 IoP Ventures LLC

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the 
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program. If not, see <http://www.gnu.org/licenses/>.

#include "testutil.h"

#ifdef WIN32
#include <shlobj.h>
#endif

#include <boost/filesystem.hpp>

boost::filesystem::path GetTempPath() {
#if BOOST_FILESYSTEM_VERSION == 3
    return boost::filesystem::temp_directory_path();
#else
    // TODO: remove when we don't support filesystem v2 anymore
    boost::filesystem::path path;
#ifdef WIN32
    char pszPath[MAX_PATH] = "";

    if (GetTempPathA(MAX_PATH, pszPath))
        path = boost::filesystem::path(pszPath);
#else
    path = boost::filesystem::path("/tmp");
#endif
    if (path.empty() || !boost::filesystem::is_directory(path)) {
        LogPrintf("GetTempPath(): failed to find temp path\n");
        return boost::filesystem::path("");
    }
    return path;
#endif
}
