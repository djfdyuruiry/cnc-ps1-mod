#! /usr/bin/env bash
# shellcheck source-path=SCRIPTDIR
set -eEuo pipefail

script_path="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

function main() {
  "${script_path}/build.sh"

  duckstation-qt "$(realpath "${script_path}/../build/ModdedGame_DEFAULT.cue")"
}

main "$@"
