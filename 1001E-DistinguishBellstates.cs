/*
	SubmissionId	:	39786236
	ContestId	:	1001
	Index	:	E
	ProblemName	:	Distinguish Bell states
	ProblemTags	:	['*special']
	ProgrammingLanguage	:	Q#
	Verdict	:	OK
*/

namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : Int
    {
        body
        {
            // your code here
            CNOT(qs[0], qs[1]);
            H(qs[0]);
            mutable ret = 0;
            if (M(qs[1]) == One) {
                set ret = 1;
            }
            set ret = ret * 2;
            if (M(qs[0]) == One) {
                set ret = ret + 1;
            }
            return ret;
        }
    }
}