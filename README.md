IoP Core
========

[![Build Status](https://img.shields.io/travis/Internet-of-People/iop-blockchain/master.svg?style=flat-square)](https://travis-ci.org/Internet-of-People/iop-blockchain)

http://iop.cash

What is IoP?
------------

IoP is an experimental digital currency that enables instant payments to
anyone, anywhere in the world. IoP uses peer-to-peer technology to operate
with no central authority: managing transactions and issuing money are carried
out collectively by the network. IoP Core is the name of open source
software which enables the use of this currency.

Development Process
-------------------

The `master` branch is regularly built and tested, but is not guaranteed to be
completely stable. [Tags](https://github.com/Internet-of-People/iop-blockchain/tags) are created
regularly to indicate new official, stable release versions of IoP Core.

The contribution workflow is described in [CONTRIBUTING.md](CONTRIBUTING.md).

The developer [mailing list](https://lists.linuxfoundation.org/mailman/listinfo/IoP-dev)
should be used to discuss complicated or controversial changes before working
on a patch set.

Testing
-------

Testing and code review is the bottleneck for development; we get more pull
requests than we can review and test on short notice. Please be patient and help out by testing
other people's pull requests, and remember this is a security-critical project where any mistake might cost people
lots of money.

### Automated Testing

Developers are strongly encouraged to write [unit tests](/doc/unit-tests.md) for new code, and to
submit new unit tests for old code. Unit tests can be compiled and run
(assuming they weren't disabled in configure) with: `make check`

There are also [regression and integration tests](/qa) of the RPC interface, written
in Python, that are run automatically on the build server.
These tests can be run (if the [test dependencies](/qa) are installed) with: `qa/pull-tester/rpc-tests.py`

The Travis CI system makes sure that every pull request is built for Windows, Linux, and OS X, and that unit/sanity tests are run automatically.

### Manual Quality Assurance (QA) Testing

Changes should be tested by somebody other than the developer who wrote the
code. This is especially important for large or high-risk changes. It is useful
to add a test plan to the pull request description if testing the changes is
not straightforward.

Translations
------------

Changes to translations as well as new translations can be submitted to
[IoP Core's Transifex page]().

Translations are periodically pulled from Transifex and merged into the git repository. See the
[translation process](doc/translation_process.md) for details on how this works.

**Important**: We do not accept translation changes as GitHub pull requests because the next
pull from Transifex would automatically overwrite them again.

Installing
----------

Please read the [installation](INSTALL.md) document.

License
-------

Copyright © 2009-2017 Libertaria Corp., Decentralized Society Foundation, IoP Ventures LLC

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

See [COPYING](COPYING) for more
information or see <http://www.gnu.org/licenses/>.
