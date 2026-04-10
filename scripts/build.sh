#! /usr/bin/env bash
# shellcheck source-path=SCRIPTDIR
set -eEuo pipefail

script_path="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

function main() {
  "${script_path}/generate-symbol-code.sh"

  pushd ~/.local/share/GameModdingUtility &> /dev/null

  wine mod_utility.exe build command-and-conquer-td

  popd &> /dev/null
}

main "$@"
