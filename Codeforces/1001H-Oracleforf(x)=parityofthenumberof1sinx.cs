/*
	SubmissionId	:	39807956
	ContestId	:	1001
	Index	:	H
	ProblemName	:	Oracle for f(x) = parity of the number of 1s in x
	ProblemTags	:	['*special']
	ProgrammingLanguage	:	Q#
	Verdict	:	OK
*/

namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (x : Qubit[], y : Qubit) : ()
    {
        body
        {
            for (i in 0..Length(x) - 1) {
                CNOT(x[i], y);
            }
        }
    }
}