# This is a branch of GCC-12.4 supporting AArch64(Arm64) on Darwin.

The branch is suitable for powerpc, i686, x86_64 and aarch64 Darwin from Darwin9 (MacOSX 10.5) through Darwin23 (macOS 14 / Sonoma) on architectures relevant to each version.

Please see README for general information on the GCC sources

The GCC 12.4 upstream release has many bug-fixes and improvements, please see the general GCC release documentation for details.

The notable changes for Darwin/macOS are:
 * better support for the dyld-based linker in Xcode 15+.
 * better support for macOS 14.
 * back-ported editions of "official" implementations for relocatable compiler and handling of `__has_feature/__has_extension`.

Please see gcc/config/aarch64/darwinpcs.md for a description of the AArch64 ABI
support.

**_The current release is GCC-12.4-darwin-r0. (June 2024)_**

This release:
 * Includes all 12.4 Upstream bug fixes.
 * I've included support for the `availability` attribute in this branch, as it is an important facility for compatibility with Apple SDKs.

Extras thanks to:
 * 'FX' (https://github.com/fxcoudert) for the main part of the ```__float128``` support, progressing upstream commits and test fixes.
 * All folks who have tested and reported issues.

Iain Sandoe, June 2024.

Please report issues for this branch to:
https://github.com/iains/gcc-12-branch/issues
