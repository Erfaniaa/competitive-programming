/*
	SubmissionId	:	39786098
	ContestId	:	1001
	Index	:	D
	ProblemName	:	Distinguish plus state and minus state
	ProblemTags	:	['*special']
	ProgrammingLanguage	:	Q#
	Verdict	:	OK
*/

namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Set (desired: Result, q1: Qubit) : ()
    {
        body
        {
            let current = M(q1);
            if (desired != current)
            {
                X(q1);
            }
        }
    }


    operation Solve (q : Qubit) : Int
    {
        body
        {
            H(q);
            let m = M(q);
            if (m == One) {
                return -1;
            }
            if (m == Zero) {
                return 1;
            }
return 1;
        }
    }
}