
"""
This script contains an array with the AOC0007260809 pseudo function names as keys corresponding to the ROR0003010717 equivalent using a list containing the renamed function and it type declaration.
This script is meant to be used by IDA's Python plugin so that every function can be updated by collaborators working on the same IDB.
"""

convert = {
    "sub_4183C0": [
        "?Get_Closest_Resource@Visible_Resource_Manager@@QAEPAUVISIBLE_RESOURCE_REC@@HHHHPAHH@Z",
        "VISIBLE_RESOURCE_REC *__thiscall Visible_Resource_Manager__Get_Closest_Resource(Visible_Resource_Manager *this, int Xpos, int Ypos, int Zone, int ResType, int *excList, int elSize)"]
}
