#!/usr/bin/env bash
DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
cd "$DIR"
OUTPUT_DIR="$DIR"
MAKE_LUABINDING="$QUICK_V3_ROOT"/quick/bin/compile_luabinding.sh
$MAKE_LUABINDING -pfx zq -d "$OUTPUT_DIR" zq_quick_tolua_luabinding.tolua
