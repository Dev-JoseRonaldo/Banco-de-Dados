import { Card } from '../../components/Card';
import { FaUserGraduate, FaChalkboardTeacher, FaBuilding } from 'react-icons/fa';

export default function Cadastro() {
  return (
    <div className="flex flex-col items-center justify-center min-h-screen bg-[#f9fafb] text-black p-6">
      <h1 className="text-7xl font-bold mb-14">LkCIn</h1>
      <div className="grid grid-cols-1 md:grid-cols-3 gap-6 w-full max-w-3xl">
        <Card label="Sou Aluno" route="/cadastro/aluno" icon={<FaUserGraduate />} />
        <Card label="Sou Professor" route="/cadastro/professor" icon={<FaChalkboardTeacher />} />
        <Card label="Sou Empresa" route="/cadastro/empresa" icon={<FaBuilding />} />
      </div>
    </div>
  );
}