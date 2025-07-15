#!/usr/bin/env python3
"""
A simple test runner script that executes a built executable against input files
and compares its stdout to expected output files, normalizing trailing whitespace.

Usage:
  python test_runner.py <name>

This will run ../build/<name> on each input file in ../tests/<name>/suite,
store actual outputs and diffs in ../tests/<name>/results, and
write a summary log to ../tests/<name>/<name>.log
"""
import argparse
import subprocess
import sys
from pathlib import Path
import difflib

def main():
    parser = argparse.ArgumentParser(
        description="Run tests for a given executable and test suite."
    )
    parser.add_argument(
        "name",
        help="Name of the executable (in build/) and test suite (in tests/<name>/suite)"
    )
    args = parser.parse_args()
    name = args.name

    # Base directories (assuming current working directory is project root)
    cwd = Path.cwd()
    exe_path = cwd / "build" / name
    suite_dir = cwd / "tests" / name / "suite"
    results_dir = cwd / "tests" / name / "results"
    log_path = cwd / "tests" / name / f"{name}.log"

    # Validate paths
    if not exe_path.is_file():
        print(f"Error: Executable not found: {exe_path}")
        sys.exit(1)
    if not suite_dir.is_dir():
        print(f"Error: Test suite directory not found: {suite_dir}")
        sys.exit(1)

    # Prepare results directory
    results_dir.mkdir(parents=True, exist_ok=True)

    # Gather all input files (sorted by numeric prefix)
    inputs = sorted(
        suite_dir.glob("*.in"),
        key=lambda p: int(p.stem)
    )

    total = len(inputs)
    passed = 0
    summary = []

    for in_file in inputs:
        test_id = in_file.stem  # e.g., '1', '2', etc.
        out_file = suite_dir / f"{test_id}.out"

        # Run the executable
        proc = subprocess.run(
            [str(exe_path), str(in_file)],
            capture_output=True,
            text=True
        )
        actual = proc.stdout

        # Save actual output for manual inspection (raw)
        actual_path = results_dir / f"{test_id}.actual"
        actual_path.write_text(actual)

        # Compare with expected output, ignoring trailing whitespace
        if out_file.exists():
            expected = out_file.read_text()
            if actual.rstrip() == expected.rstrip():
                status = "PASS"
                passed += 1
            else:
                status = "FAIL"
                # Write a diff for inspection (normalize trailing whitespace)
                diff = difflib.unified_diff(
                    expected.rstrip().splitlines(keepends=True),
                    actual.rstrip().splitlines(keepends=True),
                    fromfile="expected",
                    tofile="actual"
                )
                diff_path = results_dir / f"{test_id}.diff"
                diff_path.write_text(''.join(diff))
        else:
            status = "NO_EXPECTED"

        summary.append(f"Test {test_id}: {status} (exit {proc.returncode})")

    # Final summary
    summary.append("")
    summary.append(f"Total tests: {total}")
    summary.append(f"Passed: {passed}")
    summary.append(f"Failed: {total - passed}")

    # Write log file
    log_path.write_text("\n".join(summary))

    # Print summary to stdout
    print("\n".join(summary))

if __name__ == "__main__":
    main()
