// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2014 The Bitcoin Core developers 
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

#ifndef IoP_SCRIPT_SCRIPT_ERROR_H
#define IoP_SCRIPT_SCRIPT_ERROR_H

typedef enum ScriptError_t
{
    SCRIPT_ERR_OK = 0,
    SCRIPT_ERR_UNKNOWN_ERROR,
    SCRIPT_ERR_EVAL_FALSE,
    SCRIPT_ERR_OP_RETURN,

    /* Max sizes */
    SCRIPT_ERR_SCRIPT_SIZE,
    SCRIPT_ERR_PUSH_SIZE,
    SCRIPT_ERR_OP_COUNT,
    SCRIPT_ERR_STACK_SIZE,
    SCRIPT_ERR_SIG_COUNT,
    SCRIPT_ERR_PUBKEY_COUNT,

    /* Failed verify operations */
    SCRIPT_ERR_VERIFY,
    SCRIPT_ERR_EQUALVERIFY,
    SCRIPT_ERR_CHECKMULTISIGVERIFY,
    SCRIPT_ERR_CHECKSIGVERIFY,
    SCRIPT_ERR_NUMEQUALVERIFY,

    /* Logical/Format/Canonical errors */
    SCRIPT_ERR_BAD_OPCODE,
    SCRIPT_ERR_DISABLED_OPCODE,
    SCRIPT_ERR_INVALID_STACK_OPERATION,
    SCRIPT_ERR_INVALID_ALTSTACK_OPERATION,
    SCRIPT_ERR_UNBALANCED_CONDITIONAL,

    /* CHECKLOCKTIMEVERIFY and CHECKSEQUENCEVERIFY */
    SCRIPT_ERR_NEGATIVE_LOCKTIME,
    SCRIPT_ERR_UNSATISFIED_LOCKTIME,

    /* BIP62 */
    SCRIPT_ERR_SIG_HASHTYPE,
    SCRIPT_ERR_SIG_DER,
    SCRIPT_ERR_MINIMALDATA,
    SCRIPT_ERR_SIG_PUSHONLY,
    SCRIPT_ERR_SIG_HIGH_S,
    SCRIPT_ERR_SIG_NULLDUMMY,
    SCRIPT_ERR_PUBKEYTYPE,
    SCRIPT_ERR_CLEANSTACK,

    /* softfork safeness */
    SCRIPT_ERR_DISCOURAGE_UPGRADABLE_NOPS,
    SCRIPT_ERR_DISCOURAGE_UPGRADABLE_WITNESS_PROGRAM,

    /* segregated witness */
    SCRIPT_ERR_WITNESS_PROGRAM_WRONG_LENGTH,
    SCRIPT_ERR_WITNESS_PROGRAM_WITNESS_EMPTY,
    SCRIPT_ERR_WITNESS_PROGRAM_MISMATCH,
    SCRIPT_ERR_WITNESS_MALLEATED,
    SCRIPT_ERR_WITNESS_MALLEATED_P2SH,
    SCRIPT_ERR_WITNESS_UNEXPECTED,

    SCRIPT_ERR_ERROR_COUNT
} ScriptError;

#define SCRIPT_ERR_LAST SCRIPT_ERR_ERROR_COUNT

const char* ScriptErrorString(const ScriptError error);

#endif // IoP_SCRIPT_SCRIPT_ERROR_H
