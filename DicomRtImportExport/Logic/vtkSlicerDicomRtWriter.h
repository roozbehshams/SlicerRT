/*==============================================================================

  Copyright (c) Radiation Medicine Program, University Health Network,
  Princess Margaret Hospital, Toronto, ON, Canada. All Rights Reserved.

  See COPYRIGHT.txt
  or http://www.slicer.org/copyright/copyright.txt for details.

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

  This file was originally developed by Kevin Wang, Radiation Medicine Program, 
  University Health Network and was supported by Cancer Care Ontario (CCO)'s ACRU program 
  with funds provided by the Ontario Ministry of Health and Long-Term Care
  and Ontario Consortium for Adaptive Interventions in Radiation Oncology (OCAIRO).

==============================================================================*/

// .NAME vtkSlicerDicomRtExportReader -
// .SECTION Description
// This class manages the Reader associated with reading, saving,
// and changing propertied of the volumes


#ifndef __vtkSlicerDicomRtExportReader_h
#define __vtkSlicerDicomRtExportReader_h

#include "vtkSlicerDicomRtImportExportModuleLogicExport.h"

#include "vtkObject.h"

#include "rt_study.h"

// Due to some reason the Python wrapping of this class fails, therefore
// put everything between BTX/ETX to exclude from wrapping.
// TODO #210: investigate why the wrapping fails
//BTX

/// \ingroup SlicerRt_QtModules_DicomRtExport
class VTK_SLICER_DICOMRTIMPORTEXPORT_LOGIC_EXPORT vtkSlicerDicomRtWriter :  public vtkObject
{
public:
  static vtkSlicerDicomRtWriter *New();
  vtkTypeMacro(vtkSlicerDicomRtWriter, vtkObject);
  void PrintSelf(ostream& os, vtkIndent indent);

  /// TODO: Description, argument names and descriptions
  void SetImage(const Plm_image::Pointer&);

  /// TODO: Description, argument names and descriptions
  void SetDose(const Plm_image::Pointer&);

  /// TODO: Description, argument names and descriptions
  void AddStructure(UCharImageType::Pointer, const char*, double*);
  
  /// TODO: Description, argument names and descriptions
  void Write();

public:
  // Macros for accessing strings
  vtkGetStringMacro(PatientName);
  vtkSetStringMacro(PatientName);
  vtkGetStringMacro(PatientID);
  vtkSetStringMacro(PatientID);
  vtkGetStringMacro(PatientSex);
  vtkSetStringMacro(PatientSex);
  vtkGetStringMacro(StudyDate);
  vtkSetStringMacro(StudyDate);
  vtkGetStringMacro(StudyTime);
  vtkSetStringMacro(StudyTime);
  vtkGetStringMacro(StudyDescription);
  vtkSetStringMacro(StudyDescription);
  vtkGetStringMacro(StudyInstanceUid);
  vtkSetStringMacro(StudyInstanceUid);
  vtkGetStringMacro(StudyID);
  vtkSetStringMacro(StudyID);

  vtkGetStringMacro(FileName);
  vtkSetStringMacro(FileName);
  
protected:
  std::string formatColorString (const double *color);
  vtkSlicerDicomRtWriter();
  virtual ~vtkSlicerDicomRtWriter();

  // Parameters that get written into DICOM header
  char* PatientName;
  char* PatientID;
  char* PatientSex;
  char* StudyDate;
  char* StudyTime;
  char* StudyDescription;
  char* StudyInstanceUid;
  char* StudyID;

  char* ImageSeriesDescription;
  int ImageSeriesNumber;

  /// Output directory
  char* FileName;

  /// TODO:
  Rt_study RtStudy;

private:
  vtkSlicerDicomRtWriter(const vtkSlicerDicomRtWriter&); // Not implemented
  void operator=(const vtkSlicerDicomRtWriter&);               // Not implemented
};

//ETX

#endif
