/*
	SubmissionId	:	39807675
	ContestId	:	1001
	Index	:	C
	ProblemName	:	Generate GHZ state
	ProblemTags	:	['*special']
	ProgrammingLanguage	:	Q#
	Verdict	:	OK
*/

namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : ()
    {
        body
        {
            H(qs[0]);
            for (i in 1..Length(qs) - 1) {
                CNOT(qs[0], qs[i]);
            }
        }
    }
}