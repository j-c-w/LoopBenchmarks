The aim of this is to collate some benchmark suites with their loop kernels.
In each folder, there is an INFO file which contains license information
and source information for the benchmarks.

For ease of compilation to CGRAs, relevant loops have been isolated.


I have taken the following benchmark suites, and extracted loop kernels from them:
 - https://github.com/embench/embench-iot

#Loop Selection Policy
We select for-loops from benchmarks that are amenable to CGRA compilation. Selected loops must have the following properties:
 - Must be loop pipeline-able (e.g. no returns/breaks/inter-loop dependencies etc.).  Exemptions have been made where easy transformations to pipeline-able loops exist.
 - Must contain at least one arithmetic operation.  While memcopy is a worthwhile optimization target, it is not particularly interesting as a compilation target.
 - Must not be too large.  This has been subjective, but loops with hundreds of operations per-iteration have been skipped.
 - Must not have too many branches.  This has also been done in a fairly subjective manner, but the aim is to avoid loops where CGRAs would not accelerate the loop effectively (usually because it contains branches that are often not taken)
 - May have function calls, but these calls must be 'simple', i.e. no loops/excessive branching

We have also performed various steps a CGRA compiler would expect to do:
 - Re-roll manually unrolled loops.
 - Inline functions into loops.
