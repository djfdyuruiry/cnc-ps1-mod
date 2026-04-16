#! /usr/bin/env bash
# shellcheck source-path=SCRIPTDIR
set -eEuo pipefail

script_path="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

function main() {
  "${script_path}/generate-symbol-code.sh"

  pushd ~/.local/share/GameModdingUtility &> /dev/null

  local log_file
  log_file="$(mktemp)"

  wine mod_utility.exe build command-and-conquer-td > >(tee "${log_file}") 2>&1

  if grep "COMPILATION ERROR" "${log_file}" &> /dev/null || grep "Linker failed:" "${log_file}" &> /dev/null; then
    rm -f "${log_file}"
    exit 1
  fi

  rm -f "${log_file}"
  popd &> /dev/null
}

main "$@"
