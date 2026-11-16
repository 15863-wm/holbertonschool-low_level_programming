# Green Efficiency Analysis

## Measurement Methodology

All programs were compiled with `gcc -Wall -Werror -Wextra -pedantic` and no optimization flag, using `-std=gnu99` for the baseline loop (it uses `long long`) and `-std=gnu89` for the other two. Time was measured with `clock()` divided by `CLOCKS_PER_SEC`. The baseline loop ran three times and the algorithm comparison ran five times. In the instrumented program, `TOTAL` starts before the first phase and ends after the last one. Each phase (`BUILD_DATA`, `PROCESS`, `REDUCE`) is bracketed only by the call it measures, and all printing happens outside the timed regions. This keeps the boundaries consistent and guarantees `TOTAL` is at least as large as every phase.

## Observed Performance Differences

The baseline loop (100,000,000 iterations) took 0.227210, 0.229340 and 0.228849 seconds, a mean of 0.228466 seconds and a spread of about 0.9%. That is roughly 2.28 ns per iteration.

In the comparison program, the naive nested-loop version took 2.767784, 2.758813, 2.758293, 2.757620 and 2.774124 seconds (mean 2.763327). The single-pass version measured 0.000106 seconds in all five runs. The naive version was therefore about 26,069 times slower.

The source explains this gap. The naive version performs n(n+1)/2 = 1,250,025,000 inner iterations for n = 50,000, against 50,000 for the single pass, a ratio of about 25,000. The measured cost per iteration is similar: about 2.21 ns for the naive version and 2.12 ns for the single pass. The difference comes from how many operations are executed, not from slower operations.

The instrumented program reported TOTAL 0.000848 s, BUILD_DATA 0.000285 s, PROCESS 0.000390 s and REDUCE 0.000140 s. The phases sum to 0.000815 s, and the largest phase, PROCESS, accounts for 46% of TOTAL.

## Relation Between Runtime and Energy Consumption

No energy or power was measured in this experiment, so no energy figure is reported. The only measured quantity is CPU time. Because energy equals average power multiplied by time, if the two comparison programs drew similar power, the energy ratio would follow the time ratio of about 26,069. This is a conditional statement, not a measurement. What the data does support is that the naive version keeps the processor busy for 2.763327 seconds on a task the single-pass version finishes in 0.000106 seconds.

## Limitations of the Experiment

- **Timer granularity:** the single-pass time printed 0.000106 seconds in all five runs, which suggests it sits near the timer's resolution. The 26,069 ratio is therefore approximate, and the instrumented phases are similarly short.
- **Small samples:** only three baseline runs and five comparison runs were recorded.
- **Variability across sessions:** in separate terminal sessions on the same machine, baseline times ranged from 0.227210 to 0.237510 seconds, about 4.5% apart.
- **No optimization:** everything was built without optimization flags, so the results describe unoptimized code only.
- **Different outputs:** the two algorithms return different counts (625025000 and 25000), so the comparison measures cost, not equivalent results.
- **Single machine:** no other hardware was tested.

## Practical Engineering Takeaway

Reducing the number of operations gave by far the largest improvement: replacing the nested loop cut the measured time from 2.763327 seconds to 0.000106 seconds without any hardware change. Because baseline measurements varied by less than 5%, differences this large can be trusted, while differences of a few percent cannot. Engineers should repeat measurements, report means and spread, and treat energy conclusions as unproven until power is actually measured.
