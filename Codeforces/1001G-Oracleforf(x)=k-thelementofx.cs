/*
	SubmissionId	:	39807873
	ContestId	:	1001
	Index	:	G
	ProblemName	:	Oracle for f(x) = k-th element of x
	ProblemTags	:	['*special']
	ProgrammingLanguage	:	Q#
	Verdict	:	OK
*/

namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (x : Qubit[], y : Qubit, k : Int) : ()
    {
        body
        {
            CNOT(x[k], y);
        }
    }
}