execute_process(
    COMMAND qmake ${CMAKE_CURRENT_SOURCE_DIR}/field_computation.pro
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    COMMAND_ECHO STDOUT
    OUTPUT_VARIABLE outVar
)

execute_process(
    COMMAND make -j6
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    COMMAND_ECHO STDOUT
    OUTPUT_VARIABLE outVar
)

#execute_process(
#    COMMAND g++ ${CMAKE_CURRENT_BINARY_DIR}/adjust_parameter.o
#    ${CMAKE_CURRENT_BINARY_DIR}/ArrayKernel.o
#    ${CMAKE_CURRENT_BINARY_DIR}/BaseKernel.o
#    ${CMAKE_CURRENT_BINARY_DIR}/BaseProperty.o
#    ${CMAKE_CURRENT_BINARY_DIR}/BaseReader.o
#    ${CMAKE_CURRENT_BINARY_DIR}/BaseWriter.o
#    ${CMAKE_CURRENT_BINARY_DIR}/BinaryHelper.o
#    ${CMAKE_CURRENT_BINARY_DIR}/colamd.o
#    ${CMAKE_CURRENT_BINARY_DIR}/commonlib.o
#    ${CMAKE_CURRENT_BINARY_DIR}/determine_geometry.o
#    ${CMAKE_CURRENT_BINARY_DIR}/Endian.o
#    ${CMAKE_CURRENT_BINARY_DIR}/fortify.o
#    ${CMAKE_CURRENT_BINARY_DIR}/generate_patch.o
#    ${CMAKE_CURRENT_BINARY_DIR}/get_boundary_geometry.o
#    ${CMAKE_CURRENT_BINARY_DIR}/get_constraint_matrix.o
#    ${CMAKE_CURRENT_BINARY_DIR}/get_constraint_rhs.o
#    ${CMAKE_CURRENT_BINARY_DIR}/get_default_parameter.o
#    ${CMAKE_CURRENT_BINARY_DIR}/get_param_str.o
#    ${CMAKE_CURRENT_BINARY_DIR}/get_variable_indicators.o
#    ${CMAKE_CURRENT_BINARY_DIR}/get_variable.o
#    ${CMAKE_CURRENT_BINARY_DIR}/ini.o
#    ${CMAKE_CURRENT_BINARY_DIR}/IOManager.o
#    ${CMAKE_CURRENT_BINARY_DIR}/load_save.o
#    ${CMAKE_CURRENT_BINARY_DIR}/lp_crash.o
#    ${CMAKE_CURRENT_BINARY_DIR}/lp_Hash.o
#    ${CMAKE_CURRENT_BINARY_DIR}/lp_lib.o
#    ${CMAKE_CURRENT_BINARY_DIR}/lp_LUSOL.o
#    ${CMAKE_CURRENT_BINARY_DIR}/lp_matrix.o
#    ${CMAKE_CURRENT_BINARY_DIR}/lp_MDO.o
#    ${CMAKE_CURRENT_BINARY_DIR}/lp_mipbb.o
#    ${CMAKE_CURRENT_BINARY_DIR}/lp_MPS.o
#    ${CMAKE_CURRENT_BINARY_DIR}/lp_params.o
#    ${CMAKE_CURRENT_BINARY_DIR}/lp_presolve.o
#    ${CMAKE_CURRENT_BINARY_DIR}/lp_price.o
#    ${CMAKE_CURRENT_BINARY_DIR}/lp_pricePSE.o
#    ${CMAKE_CURRENT_BINARY_DIR}/lp_report.o
#    ${CMAKE_CURRENT_BINARY_DIR}/lp_rlp.o
#    ${CMAKE_CURRENT_BINARY_DIR}/lp_scale.o
#    ${CMAKE_CURRENT_BINARY_DIR}/lp_simplex.o
#    ${CMAKE_CURRENT_BINARY_DIR}/lp_SOS.o
#    ${CMAKE_CURRENT_BINARY_DIR}/lp_utils.o
#    ${CMAKE_CURRENT_BINARY_DIR}/lp_wlp.o
#    ${CMAKE_CURRENT_BINARY_DIR}/lusol.o
#    ${CMAKE_CURRENT_BINARY_DIR}/mmio.o
#    ${CMAKE_CURRENT_BINARY_DIR}/myblas.o
#    ${CMAKE_CURRENT_BINARY_DIR}/OBJReader.o
#    ${CMAKE_CURRENT_BINARY_DIR}/OBJWriter.o
#    ${CMAKE_CURRENT_BINARY_DIR}/OFFReader.o
#    ${CMAKE_CURRENT_BINARY_DIR}/OFFWriter.o
#    ${CMAKE_CURRENT_BINARY_DIR}/OMFormat.o
#    ${CMAKE_CURRENT_BINARY_DIR}/OMReader.o
#    ${CMAKE_CURRENT_BINARY_DIR}/omstream.o
#    ${CMAKE_CURRENT_BINARY_DIR}/OMWriter.o
#    ${CMAKE_CURRENT_BINARY_DIR}/Patch.o
#    ${CMAKE_CURRENT_BINARY_DIR}/plylib.o
#    ${CMAKE_CURRENT_BINARY_DIR}/PLYReader.o
#    ${CMAKE_CURRENT_BINARY_DIR}/PLYWriter.o
#    ${CMAKE_CURRENT_BINARY_DIR}/PolyConnectivity.o
#    ${CMAKE_CURRENT_BINARY_DIR}/qr_mapping.o
#    ${CMAKE_CURRENT_BINARY_DIR}/quadwild.o
#    ${CMAKE_CURRENT_BINARY_DIR}/RandomNumberGenerator.o
#    ${CMAKE_CURRENT_BINARY_DIR}/STLReader.o
#    ${CMAKE_CURRENT_BINARY_DIR}/STLWriter.o
#    ${CMAKE_CURRENT_BINARY_DIR}/switch_pattern.o
#    ${CMAKE_CURRENT_BINARY_DIR}/TriConnectivity.o
#    ${CMAKE_CURRENT_BINARY_DIR}/VTKWriter.o
#    ${CMAKE_CURRENT_BINARY_DIR}/yacc_read.o
#    -shared -o libquadwild.so
#    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
#    COMMAND_ECHO STDOUT
#    OUTPUT_VARIABLE outVar
#)
#
