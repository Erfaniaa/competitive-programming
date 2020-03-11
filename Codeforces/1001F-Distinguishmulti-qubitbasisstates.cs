/*
	SubmissionId	:	39806957
	ContestId	:	1001
	Index	:	F
	ProblemName	:	Distinguish multi-qubit basis states
	ProblemTags	:	['*special']
	ProgrammingLanguage	:	Q#
	Verdict	:	OK
*/

namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[], bits0 : Bool[], bits1 : Bool[]) : Int
    {
        body
        {
            // your code here
            for (i in 0..Length(qs) - 1) {
                if (M(qs[i]) == One && bits0[i] == false) {
                    return 1;
                }
                if (M(qs[i]) == Zero && bits0[i] == true) {
                    return 1;
                }
                if (M(qs[i]) == One && bits1[i] == false) {
                    return 0;
                }
                if (M(qs[i]) == Zero && bits1[i] == true) {
                    return 0;
                }
            }
            return 0;
        }
    }

}