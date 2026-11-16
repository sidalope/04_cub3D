#!/bin/bash

cd tests || exit 1

BIN=../cub3D
RUN_SECONDS=0.2
LOG=output/valgrind.txt

mkdir -p "$(dirname "$LOG")"

passed=0
failed=0

report() {
	echo "$1" | tee -a "$LOG"
}

pass() {
	report "PASS: $1"
	passed=$((passed + 1))
}

fail() {
	report "FAIL: $1"
	failed=$((failed + 1))
}

printf "~~ All Tests ~~\n\n" > "$LOG"

run_cub() {
	echo "=== $1 ===" >> "$LOG"
	output=$(timeout --kill-after=1 "$RUN_SECONDS" "$BIN" "$1" 2>&1)
	status=$?
	printf '%s\n' "$output" >> "$LOG"
}

test_valid() {
	run_cub "$1"
	case $status in
		124) pass "$1 (still running after ${RUN_SECONDS}s)" ;;
		0)   pass "$1 (exited cleanly)" ;;
		137) fail "$1 (ignored SIGTERM, had to be killed)" ;;
		*)   fail "$1 (exit status $status)" ;;
	esac
}

test_invalid() {
	run_cub "$1"
	case $status in
		124) fail "$1 (still running after ${RUN_SECONDS}s, should have been rejected)" ;;
		137) fail "$1 (ignored SIGTERM, had to be killed)" ;;
		0)   fail "$1 (exited with status 0, should have been rejected)" ;;
		*)
			if [ "$(head -n 1 <<< "$output")" = "Error" ]; then
				pass "$1 (rejected, exit status $status)"
			else
				fail "$1 (exit status $status, but output does not start with Error)"
			fi
			;;
	esac
}

if [ ! -x "$BIN" ]; then
	report "FAIL: $BIN not found. make it first"
	exit 1
fi

for cub in maps/valid/*.cub; do
	test_valid "$cub"
done

for cub in maps/invalid/*; do
	test_invalid "$cub"
done

report "--- $passed passed, $failed failed ---"
[ "$failed" -eq 0 ]
