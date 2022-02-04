{ pkgs ? import<nixpkgs> {} }:

with pkgs;

mkShell {
	buildInputs = [ gcc ];
	SHELL_NAME = "LoopBenchmarks";
}
